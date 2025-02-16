import numpy as np
from typing import List, Tuple

class HillCipher:
    @staticmethod
    def matrix_mod_inverse(matrix: np.ndarray, modulus: int) -> np.ndarray:
        """Calculate the modular multiplicative inverse of a matrix."""
        det = int(round(np.linalg.det(matrix)))
        det_inverse = pow(det % modulus, -1, modulus)
        adjugate = np.round(det * np.linalg.inv(matrix)).astype(int)
        return np.mod(adjugate * det_inverse, modulus)

    @staticmethod
    def text_to_numbers(text: str) -> List[int]:
        """Convert text to numbers (A=0, B=1, ..., Z=25)."""
        try:
            numbers = []
            for c in str(text):  # Aseguramos que text sea string
                if c.isalpha():
                    number = ord(c.upper()) - ord('A')
                    numbers.append(number)
            return numbers
        except Exception as e:
            print(f"Error en text_to_numbers: {e}")
            raise

    @staticmethod
    def numbers_to_text(numbers: List[int]) -> str:
        """Convert numbers back to text."""
        return ''.join(chr(int(n) % 26 + ord('A')) for n in numbers)

    @staticmethod
    def pad_text(numbers: List[int], block_size: int) -> Tuple[List[int], int]:
        padding = block_size - (len(numbers) % block_size)
        if padding < block_size:
            return numbers + [23] * padding, padding
        return numbers, 0

    @staticmethod
    def encrypt_hill(text: str, key_matrix: List[List[int]]) -> Tuple[str, int]:
        """Encrypt text using HillCipher cipher."""
        key = np.array(key_matrix, dtype=int)
        block_size = len(key_matrix)
        
        numbers = HillCipher.text_to_numbers(text)
        numbers, padding_count = HillCipher.pad_text(numbers, block_size)
        
        result = []
        for i in range(0, len(numbers), block_size):
            block = np.array(numbers[i:i + block_size], dtype=int)
            encrypted_block = np.mod(np.dot(key, block), 26)
            result.extend(encrypted_block)
            
        return HillCipher.numbers_to_text(result), padding_count

    @staticmethod
    def decrypt_hill(text: str, key_matrix: List[List[int]], padding_count: int = 0) -> str:
        """Decrypt text using HillCipher cipher."""
        key = np.array(key_matrix, dtype=int)
        inverse_key = HillCipher.matrix_mod_inverse(key, 26)
        block_size = len(key_matrix)
        
        numbers = HillCipher.text_to_numbers(text)
        
        result = []
        for i in range(0, len(numbers), block_size):
            block = np.array(numbers[i:i + block_size], dtype=int)
            decrypted_block = np.mod(np.dot(inverse_key, block), 26)
            result.extend(decrypted_block)
            
        if padding_count > 0:
            result = result[:-padding_count]
            
        return HillCipher.numbers_to_text(result)