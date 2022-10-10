
def kunal(a):
    if(a==1):
        return 1
    return a * (kunal(a-1))

a=int(input("Enter the value"))
print(kunal(a))
