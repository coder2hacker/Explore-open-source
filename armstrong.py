n=int(input("enter the number : "))
sum=0
t=n

while t>0:
     d=t%10
     sum=sum+d**3
     t //=10

if sum==n:
    print(n," is armstrong number")
else:
    print(n," is not armstrong number")