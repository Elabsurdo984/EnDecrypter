class RC4Cipher:
    @staticmethod
    def _init_sbox(key: bytes) -> list:
        S = list(range(256))
        j = 0
        key_length = len(key)
        
        for i in range(256):
            j = (j + S[i] + key[i % key_length]) % 256
            S[i], S[j] = S[j], S[i]
            
        return S

    @staticmethod
    def encrypt_rc4(text: str, key: bytes) -> bytes:
        S = RC4Cipher._init_sbox(key)
        i = j = 0
        result = []
        
        for byte in text.encode():
            i = (i + 1) % 256
            j = (j + S[i]) % 256
            S[i], S[j] = S[j], S[i]
            k = S[(S[i] + S[j]) % 256]
            result.append(byte ^ k)
            
        return bytes(result)

    @staticmethod
    def decrypt_rc4(encrypted_text: bytes, key: bytes) -> str:
        S = RC4Cipher._init_sbox(key)
        i = j = 0
        result = []
        
        for byte in encrypted_text:
            i = (i + 1) % 256
            j = (j + S[i]) % 256
            S[i], S[j] = S[j], S[i]
            k = S[(S[i] + S[j]) % 256]
            result.append(byte ^ k)
            
        return bytes(result).decode()