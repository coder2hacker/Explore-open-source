vet = [0]*6
mat = [0]*6
for x in range(6):
    mat[x] = [0]*6

for lin in range(6):
    for col in range(6):
        mat[lin][col] = input('Digite um valor: ')
print mat

for lin in range(6):
    for col in range(6):
        print lin,col
        if lin == col:
            print 'DP', lin, col
            vet[lin] = mat[lin][col]
print vet
