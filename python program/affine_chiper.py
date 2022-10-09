"""
    Affine chiper made by combining 
    The Multiplicative Cipher and The Caesar Cipher
    """


class affine_chiper:

    def __init__(self, input_text, keyA, keyB):
        self.input_text = input_text
        self.keyA = keyA
        self.keyB = keyB


    def encrypt(self):
        chiperText = ""
        abjad = "abcdefghijklmnopqrstuvwxyz 1234567890-_=+[],.<>/?"
        for words in self.input_text.lower():
            wordsIndex = (abjad.find(words) * self.keyA + self.keyB) % len(abjad)
            chiperText += abjad[wordsIndex]
        return chiperText

    def decrypt(self):
        plainText = ""
        abjad = "abcdefghijklmnopqrstuvwxyz 1234567890-_=+[],.<>/?"
        for words in self.input_text.lower():
            wordsIndex = ((abjad.find(words) - self.keyB) / self.keyA) % len(abjad)
            plainText += abjad[int(wordsIndex)]

        return plainText

def main():

    input_text = "Hello"
    KeyA = 2
    KeyB = 3
    encrypt = affine_chiper(input_text, KeyA, KeyB)

    encrypt_text = encrypt.encrypt()


    decrypt = affine_chiper(encrypt_text, KeyA, KeyB)

    decrypt_text = decrypt.decrypt()

    print("encrypt text =",encrypt_text)
    print("decrypt text = ", decrypt_text)


if __name__ == "__main__":
    main()