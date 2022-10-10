def recursion_fib(a):
    if(a==0):
        return 0
    elif(a==1):
        return 1
    else:
        return recursion_fib(a-1) + recursion_fib(a-2)

print(recursion_fib(5))