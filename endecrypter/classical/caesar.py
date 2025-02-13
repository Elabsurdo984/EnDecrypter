class CaesarCipher:
    @staticmethod
    def encrypt_caesar(text: str, shift: int) -> str:
        result = []
        for char in text:
            if char.isalpha():
                base = ord('A') if char.isupper() else ord('a')
                shifted = (ord(char) - base + shift) % 26 + base
                result.append(chr(shifted))
            else:
                result.append(char)
        return ''.join(result)

    @staticmethod
    def decrypt_caesar(text: str, shift: int) -> str:
        return CaesarCipher.encrypt(text, -shift)