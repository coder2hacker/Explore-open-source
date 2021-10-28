#using while loop is more convinient with lists& dicts.
unconfirmed_users=['Ram','Shyam','Krishna']
confirmed_users=[]

#Verify each user until there are no unconfirmed users
#Move each verified user into the list of confirmed users.
while unconfirmed_users:
	currnent_user=unconfirmed_users.pop()
	print(f'Verifying user: {currnent_user.title()}')
	confirmed_users.append(currnent_user)

#Display all confirmed users
print('\n The following users have been confirmed')
for confirmed_user in confirmed_users:
	print(confirmed_user.title())

#If we want to remove all instances of a particular value from a list
pets=['dog','cat','dog','goldfish','cat','rabbit','cat']
print(pets)
while 'cat' in pets:
    pets.remove('cat')

print(pets)

responses={}

#Set a flag to indicate thet polling is active
polling_active=True

while polling_active:
	#Prompt for that person's name& response
	name=input('\nWhat is your name?')
	response=input('\nWhich mountain do you like')

	#Store the response in the dictionary
	responses[name] = response

	#Find out if anyone else is going to take the poll
	repeat=input('Would you like to run the poll?(yes/no)')
	if repeat=='no':
		polling_active=False

#Polling is complete . Show the result
print('\n----Poll Result----')
for name,response in responses.item():
	print(f"{name} would like to climb {response}.")

x=1;
for n in range(1,n+1):
	print(n+"*"+x+"="+(n*x))
	x+=1;

#reading input from user until -1 is entered & printing the largest of it
n=int(input())
max=n
while(n!=-1):
	#read remaining numbers inside loop
	n=int(input())
	if(max<n):
		max=n

x=1
sum=0
while x<=100:
	value=int(input())
	if(value<0):
		#-ve number:no need to go around loop anymore 
		break
	sum+=value
	x+=1













