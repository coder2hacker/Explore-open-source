def HCF(a, b):
    ##AKA GCD(greatest common divisor)
    if b == 0:
        return a
    return HCF(b, a % b)


##efficient method to find hcf

def LCM(a, b):
    return (a * b) / HCF(a, b)

i = int(input())
j = int(input())
print("LCM : ", LCM(i, j))
print("HCF : ", HCF(i, j))
