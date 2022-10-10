#Program to find length of list using recursion

len=0
def length(a):
    global len 
    if a :
        len = len +1
        length(a[1:])
    return len

list=[4,9,64,121,169,196] 
print(length(list))   

