# Program to convert decimal to binary

def Decimal_to_Binary(d):
    b=''
    d=int(d)
    while(d != 0):
        r = d % 2
        d = d // 2
        b += str(r)
    b = b[-1::-1]
    return (b) 
n=int(input("Enter a decimal number:"))       
print("The binary equivalent of decimal ", n, "is",Decimal_to_Binary(n))