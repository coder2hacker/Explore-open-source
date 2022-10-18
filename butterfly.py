n=5

for i in range(n-1):
    p=65
    for j in range(i+1):
        print(chr(p), end=' ')
        p+=1
    for j in range(i,n-1):
        print(' ',end=' ')
    
    for j in range(i,n-1):
        print(' ', end=' ')
    
    for j in range(i+1):
        print(chr(p),end=' ')
        p+=1
    print()
    #Upper phase completed
for i in range(n):
    p=65
    for j in range(i,n):
        print(chr(p), end=' ')
        p+=1
    for j in range(i):
        print(' ',end=' ')
    for j in range(i):
        print(' ', end=' ')
    for i in range(i,n):
        print(chr(p), end=' ' )
        p+=1
    
    print()