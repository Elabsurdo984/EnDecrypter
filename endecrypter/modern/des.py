from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

class DESCipher:
    @staticmethod
    def encrypt_des(text: str, key: bytes) -> bytes:
        key = key.ljust(8, b'\0')[:8]
        cipher = DES.new(key, DES.MODE_CBC)
        padded_text = pad(text.encode(), DES.block_size)
        encrypted_text = cipher.encrypt(padded_text)
        return cipher.iv + encrypted_text

    @staticmethod
    def decrypt_des(encrypted_text: bytes, key: bytes) -> str:
        key = key.ljust(8, b'\0')[:8]
        iv = encrypted_text[:8]
        encrypted_text = encrypted_text[8:]
        cipher = DES.new(key, DES.MODE_CBC, iv)
        decrypted_text = unpad(cipher.decrypt(encrypted_text), DES.block_size)
        return decrypted_text.decode()