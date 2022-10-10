# cook your dish here
t=int(input())
n=int(input())
m=int(input())
o=int(input())

while t!=0: 
    if o >= (n+m) :
        print(2)
    elif o > m:
        print(1)
    else :
        print(0)