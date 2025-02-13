import string

class PolyalphabeticCipher:
    @staticmethod
    def _clean_text(text: str) -> str:
        return ''.join(c for c in text.upper() if c in string.ascii_uppercase)

    @staticmethod
    def encrypt(text: str, key: str) -> str:
        alphabet = string.ascii_uppercase
        clean_text = PolyalphabeticCipher._clean_text(text)
        clean_key = PolyalphabeticCipher._clean_text(key)
        
        result = []
        for i, char in enumerate(clean_text):
            if char in alphabet:
                shift = alphabet.index(clean_key[i % len(clean_key)])
                new_char = alphabet[(alphabet.index(char) + shift) % 26]
                result.append(new_char)
            else:
                result.append(char)
        return ''.join(result)

    @staticmethod
    def decrypt(text: str, key: str) -> str:
        alphabet = string.ascii_uppercase
        clean_text = PolyalphabeticCipher._clean_text(text)
        clean_key = PolyalphabeticCipher._clean_text(key)
        
        result = []
        for i, char in enumerate(clean_text):
            if char in alphabet:
                shift = alphabet.index(clean_key[i % len(clean_key)])
                new_char = alphabet[(alphabet.index(char) - shift) % 26]
                result.append(new_char)
            else:
                result.append(char)
        return ''.join(result)
