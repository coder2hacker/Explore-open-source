magicians=['alice','david','carolina']
for m in magicians:
    print(f"{m.upper()} That was a great trick!!")
    print(m.title())
message="Hello Python World"
print(message)
s=0;
for value in range(1,5):
	print(value)
	s+=value
print(s)
numbers=list(range(1,6))
print(numbers)
even_nums=list(range(2,11,2))
print(even_nums)

squares=[]
for value in range(1,11):
	#square=value**2
	squares.append(value**2)
print(squares)
digits=list(range(0,10))
print(digits)
print(min(digits))
print(max(digits))
print(sum(digits))
squares=[value**2 for value in range(1,11)]
print(squares)
for v in range(1,21):
	print(v)
#l=list(range(1,1000001))
#for i in l:
#	print(i )
players=['sachin','virat','dhoni','jadeja']
#print(players)
print('Here are the first three players on my screen:')
for player in players[:3]:
	print(player.title())
my_foods=['pizza','falefel','carrot cake']
friend_foods=my_foods[:]
#print(friend_foods)
my_foods.append('cannoli')
friend_foods.append('ice cream')
print(my_foods)
print(friend_foods)
#This doesn't create a new list
fr_foods=my_foods
my_foods.append('choco cake')
fr_foods.append('caramel')
print(my_foods)
print(fr_foods)
i=input("Enter your number:")
print(int(i)**2)

sum=0
for i in range(1,101):
	sum+=1/i
print("Sum of reciprocals=",sum)
sum=0
for j in range(1,11):
	sum+=1/j
print(sum)
r,a,n=0.5,1,10
for i in range(1,n):
	print(a)
	a*=r
print(a,"\n")
for i in range(1,9):
	for j in range(1,6):
		print(i*j,end='\t')
	print("\n")
for i in range(1,6):
	for j in range(i,2*i):
		print(j,end='\t')
	print()
t= 'intro to py', 'amey', 101
print(t)
empty=()
singleton=12,'raju',t
print(singleton)
print(len(singleton))
print((t+singleton)[:5])
print(2*t)
roll,name,reg_course=singleton
print(name)
x1,x2,x3,x4='amey'
print(x1,x2,x3,x4)
fib=[1,1,2,3,5,8,13,21,34,55]
print(len(fib))
print(fib[2:])
print(3*[1,1,2])
x,y,z=[2,6,13]
print(x, y, z)

#L.append(x)  appends a value at end of list 
#L.extend(seq)    
#L.insert(i,x)   inserts x at index i
#L.pop(i)    removes value at index i  
#L.remove(x)   removes the value x
#L.pop()  removes last element
#L.index(x)     gives the index value itself
#L.count(x)  no. of times x occurs in the list






