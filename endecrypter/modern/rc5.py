from typing import List, Tuple
import struct
import os

class RC5Cipher:
    """
    Implementación del cifrado RC5.
    
    RC5 es un cifrado de bloque con tamaño de bloque, número de rondas
    y tamaño de clave variables. Esta implementación usa:
    - Tamaño de palabra: 32 bits (w)
    - Número de rondas: 12 (r)
    - Tamaño de clave: variable (b)
    """

    # Constantes para RC5-32/12/b
    WORD_SIZE = 32  # w (bits)
    ROUNDS = 12     # r
    P = 0xB7E15163  # P32 = Odd((e-2)*2^WORD_SIZE)
    Q = 0x9E3779B9  # Q32 = Odd((φ-1)*2^WORD_SIZE)

    @staticmethod
    def _rotate_left(value: int, shift: int, bits: int = 32) -> int:
        """Rotación circular a la izquierda."""
        shift %= bits
        return ((value << shift) | (value >> (bits - shift))) & ((1 << bits) - 1)

    @staticmethod
    def _rotate_right(value: int, shift: int, bits: int = 32) -> int:
        """Rotación circular a la derecha."""
        shift %= bits
        return ((value >> shift) | (value << (bits - shift))) & ((1 << bits) - 1)

    @classmethod
    def _expand_key(cls, key: bytes) -> List[int]:
        """
        Expande la clave en un array de subclaves.
        
        Args:
            key: Clave de entrada en bytes
            
        Returns:
            Lista de subclaves expandidas
        """
        # Convertir la clave a palabras
        key_words = []
        for i in range(0, len(key), 4):
            key_words.append(int.from_bytes(key[i:i+4].ljust(4, b'\0'), 'little'))

        # Inicializar array L
        L = key_words + [0] * (8 - len(key_words))

        # Inicializar array S
        t = 2 * (cls.ROUNDS + 1)
        S = [0] * t
        S[0] = cls.P

        # Llenar array S
        for i in range(1, t):
            S[i] = (S[i-1] + cls.Q) & 0xFFFFFFFF

        # Mezclar
        i = j = A = B = 0
        for k in range(3 * max(t, len(L))):
            A = S[i] = cls._rotate_left(S[i] + A + B, 3)
            B = L[j] = cls._rotate_left(L[j] + A + B, A + B)
            i = (i + 1) % t
            j = (j + 1) % len(L)

        return S

    @classmethod
    def encrypt_rc5(cls, text: str, key: bytes) -> bytes:
        """
        Cifra un texto usando RC5.
        
        Args:
            text: Texto a cifrar
            key: Clave de cifrado
            
        Returns:
            Datos cifrados en bytes
        """
        # Expandir la clave
        S = cls._expand_key(key)

        # Convertir texto a bytes y añadir padding si es necesario
        text_bytes = text.encode()
        padding_length = (8 - len(text_bytes) % 8) % 8
        text_bytes += bytes([padding_length] * padding_length)

        # Procesar bloques de 8 bytes (dos palabras de 32 bits)
        result = []
        for i in range(0, len(text_bytes), 8):
            block = text_bytes[i:i+8]
            A = int.from_bytes(block[0:4], 'little')
            B = int.from_bytes(block[4:8], 'little')

            A = (A + S[0]) & 0xFFFFFFFF
            B = (B + S[1]) & 0xFFFFFFFF

            for r in range(1, cls.ROUNDS + 1):
                A = (cls._rotate_left(A ^ B, B) + S[2*r]) & 0xFFFFFFFF
                B = (cls._rotate_left(B ^ A, A) + S[2*r + 1]) & 0xFFFFFFFF

            result.extend(A.to_bytes(4, 'little'))
            result.extend(B.to_bytes(4, 'little'))

        return bytes(result)

    @classmethod
    def decrypt_rc5(cls, encrypted_data: bytes, key: bytes) -> str:
        """
        Descifra datos cifrados con RC5.
        
        Args:
            encrypted_data: Datos cifrados
            key: Clave de cifrado
            
        Returns:
            Texto descifrado
        """
        # Expandir la clave
        S = cls._expand_key(key)

        # Procesar bloques cifrados
        result = bytearray()
        for i in range(0, len(encrypted_data), 8):
            block = encrypted_data[i:i+8]
            A = int.from_bytes(block[0:4], 'little')
            B = int.from_bytes(block[4:8], 'little')

            for r in range(cls.ROUNDS, 0, -1):
                B = cls._rotate_right(B - S[2*r + 1], A) ^ A
                A = cls._rotate_right(A - S[2*r], B) ^ B

            B = (B - S[1]) & 0xFFFFFFFF
            A = (A - S[0]) & 0xFFFFFFFF

            result.extend(A.to_bytes(4, 'little'))
            result.extend(B.to_bytes(4, 'little'))

        # Quitar padding
        padding_length = result[-1]
        if padding_length < 8:
            result = result[:-padding_length]

        return result.decode()

    @staticmethod
    def generate_key(size: int = 16) -> bytes:
        """
        Genera una clave aleatoria para RC5.
        
        Args:
            size: Tamaño de la clave en bytes (por defecto 16)
            
        Returns:
            Clave aleatoria en bytes
        """
        return os.urandom(size)