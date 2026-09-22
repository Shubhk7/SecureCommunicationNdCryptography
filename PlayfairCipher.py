def prepKey(key):
    result = ""
    key = key.upper()
    for c in key:
        if c.isalpha():
            if c == 'J':
                c = 'I'
            if c not in result:
                result += c
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    for c in alphabet:
        if c not in result:
            result += c
            
    return result

def createMatrix(Key, Matrix):
    Key = prepKey(Key)
    k = 0
    for i in range(5):
        for j in range(5):
            Matrix[i][j] = Key[k]
            k += 1

def findPosition(matrix, letter):
    if letter == 'J':
        letter = 'I'
    for r in range(5):
        for c in range(5):
            if matrix[r][c] == letter:
                return r, c
    return -1, -1
                
def decryptPlayfair(ciphertext, Matrix):
    text = ""
    for c in ciphertext:
        c = c.upper()
        if c == 'J':
            c = 'I'
        text += c
    if len(text) % 2 != 0:
        text += 'X'
    plaintext = ""
    for i in range(0, len(text), 2):
        r1, c1 = findPosition(Matrix, text[i])
        r2, c2 = findPosition(Matrix, text[i + 1])

        if r1 == r2:
            plaintext += Matrix[r1][(c1 - 1) % 5]
            plaintext += Matrix[r2][(c2 - 1) % 5]
        elif c1 == c2:
            plaintext += Matrix[(r1 - 1) % 5][c1]
            plaintext += Matrix[(r2 - 1) % 5][c2]
        else:
            plaintext += Matrix[r1][c2]
            plaintext += Matrix[r2][c1]
    return plaintext

def displayMatrix(Matrix):
    for i in range(5):
        for j in range(5):
            print(Matrix[i][j], end=" ")
        print()

Key = input("Enter the key: ")
Ciphertext = input("Enter the ciphertext: ")
Matrix = [['' for _ in range(5)] for _ in range(5)]
createMatrix(Key, Matrix)
displayMatrix(Matrix)
Plaintext = decryptPlayfair(Ciphertext, Matrix)
print("Plaintext:", Plaintext) 