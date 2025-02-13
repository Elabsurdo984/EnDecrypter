class TranspositionCipher:
    @staticmethod
    def encrypt_transposition(text: str, rails: int) -> str:
        if rails < 2:
            return text
            
        fence = [[] for _ in range(rails)]
        rail = 0
        direction = 1
        
        for char in text:
            fence[rail].append(char)
            if rail == 0:
                direction = 1
            elif rail == rails - 1:
                direction = -1
            rail += direction
        
        return ''.join(''.join(rail) for rail in fence)

    @staticmethod
    def decrypt_transposition(text: str, rails: int) -> str:
        if rails < 2 or not text:
            return text
            
        positions = []
        rail = 0
        direction = 1
        
        for _ in range(len(text)):
            positions.append(rail)
            if rail == 0:
                direction = 1
            elif rail == rails - 1:
                direction = -1
            rail += direction
        
        rail_indices = {i: [] for i in range(rails)}
        for i, pos in enumerate(positions):
            rail_indices[pos].append(i)
        
        result = [''] * len(text)
        current_pos = 0
        
        for rail in range(rails):
            for pos in rail_indices[rail]:
                if current_pos < len(text):
                    result[pos] = text[current_pos]
                    current_pos += 1
        
        return ''.join(result)
