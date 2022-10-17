"""kam = [5,6,2,3,5,9,3]
kam[2] = 8 
print(kam[:])
print(type(kam))
kaw = (2,3,6,2,5,3,6)

print(kaw[:])
print(type(kaw))"""

"""def kam ():
    a = 20

    def kaw ():
        a = 50
        print("a=",a)
    kaw()
    print("a=",a)    

    
a = 30
kam()
print("a=",a)"""



"""a =  int(input("enter a number"))

if a>0:
    print(a,"is a positive number ")
elif a ==0 :
    print(a,"is a zero")
else:
    print(a,"is a negative number ")"""   


"""sum = 0 
a = [2,5,3,6,2,5,1,5,2,3,6,8,9,8]

for i in a:
    sum = sum+i

print("sum is",sum"""

"""kamlesh = ["kamlesh", "chandankumar","kawticwar"]
print(len(kamlesh))

for i in range(len(kamlesh)):
    print("i love",kamlesh[i])"""


#print sum of natural number using while loop


"""n = int(input("enter the number"))
sum = 0
i = 1
while i<=n:
    sum=sum+i
    i =i+1

print("the sum of",n,"natural number is",sum)"""


#use of break statement in the while loop


"""for i in "kamlesh":
    if i == "s":
        break
    print(i)


print("the end ")"""


#use of continue statement in the loop


"""for i in "kamlesh":
    if i == "s":
        continue
        
    print(i)


print("the end ")"""

#us eof the pass statement

"""a = [1,2,3,4]
for i in a :
    pass"""


#normal function program

"""def kamlesh(name):
    print("hellow "+name)


kamlesh("MR.KAWTICWAR")"""

#ABSALUTE VALUE PROGRAM

"""def absalute_val(num):
    if num>=0:
        print(num)
    else:
        print(-num)



absalute_val(5)
absalute_val(-6)"""


#use of deafault argument

"""def kamlesh(name , msg="good morning"):
    print("hiie "+name+","+msg)

kamlesh("sak")
kamlesh("kamlesh","good afternoon")"""


#aribetery function
"""def fun(*name):
    for name in name:
        print("hii",name)

    

fun("ram","sham","suresh")"""

#factorial function using recursion

"""def factorial(x):

    if x ==1:
        return 1
    elif x == 0 :
        return 1    
    else:
        return (x*factorial(x-1))


x = int(input("enter a number:"))
print("the factorial of",x,"is",factorial(x))"""

"""def fun(x):
    if x == 4:
        return x
    else :
        return (2*fun(x+1))    


print(fun(2))"""


"""# lambda function 

double = lambda x : x*2

print(double(2))"""

#printing ven list 
"""my_list = [2,23,5,2,6,2,12,24,41]

even = list(filter(lambda x : (x%2 == 0), my_list))

print(even)"""

"""my_list = [2,23,5,2,6,2,12,24,41]

new_list = list(map(lambda x:x*2,my_list))

print(new_list)"""

#use of global keyword for modefying the golbal value

"""x = 'kamlesh'

def sample():
    global x #use of global keyword for modefying global value
    y = "kawticwar"
    x = "kammu"
    print(x)
    print(y)


sample() 
print(x)"""

"""import math
print(math.pi)
print(math.factorial(10))
print(dir(math))"""

#checking lucky person
"""import random as r 
a = int(input("enter a number between 10 to 20: "))
x = r.randrange(10,20)
if (a == x):
    print("congrts you won the lotry collect gift")
else:
    print("sorry better luck next time ")"""


"""odd  = [2,3,4]
odd.append(5) 
odd.extend([5,6,7,8])       

print(odd)"""

#diffrent set opreations 


"""a = {1,2,3,4,5}
b ={4,5,6,7,8}
print(a|b)
print(a&b)
print(a-b)
print(b-a)
print(a^b)"""

"""square = {x:x*x for x in range(6)} 
print(square)"""

#opening a file 

"""f = open("C:/Users/kamle/OneDrive/Desktop/abc/random.txt","r")
print(f.read())"""

"""import os

print(os.getcwd())"""


"""try : 
    n = int(input("enter a number: "))
    assert n % 2 == 0
except :
    print("enter a even number ")
else:
    a = 1 / n
    print(a)"""

# use of the try except block
"""
try:
    print(x)
except :
    print("oops..! error occured")    
finally:
    print("try except completed ")"""    
    
    
    
# introduction to the child and the parent class..
class bird:
    def __init__(self):
        print("birds are ready")
    def whoisthis(self):
        print("bird")
    def swim(self):
        print("swim faster")

#child class
class peguin(bird):
    def __init__(self):
        #call of super function
        super().swim()
        print("peguin is ready")
    def whoisthis(self):
        print("peguin")
    def run(self):
        print("run faster")


peggy = peguin()
runny = bird()
runny.whoisthis()
peggy.whoisthis()
peggy.swim()
peggy.run()













