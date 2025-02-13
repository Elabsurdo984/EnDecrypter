import random
import string

class MonoalphabeticCipher:
    @staticmethod
    def generate_substitution_alphabet() -> dict:
        alphabet = list(string.ascii_lowercase)
        substitute_alphabet = alphabet[:]
        random.shuffle(substitute_alphabet)
        return dict(zip(alphabet, substitute_alphabet))

    @staticmethod
    def encrypt_monoalphabetic(text: str, substitution_alphabet: dict) -> str:
        result = []
        for char in text:
            if char.lower() in substitution_alphabet:
                new_char = substitution_alphabet[char.lower()]
                result.append(new_char.upper() if char.isupper() else new_char)
            else:
                result.append(char)
        return ''.join(result)

    @staticmethod
    def decrypt_monoalphabetic(text: str, substitution_alphabet: dict) -> str:
        inverse_alphabet = {v: k for k, v in substitution_alphabet.items()}
        return MonoalphabeticCipher.encrypt(text, inverse_alphabet)