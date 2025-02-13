class Binary:
    @staticmethod
    def text_to_binary(text: str) -> str:
        return ' '.join(format(ord(c), '08b') for c in text)

    @staticmethod
    def binary_to_text(binary: str) -> str:
        binary_list = binary.split(' ')
        return ''.join(chr(int(b, 2)) for b in binary_list)