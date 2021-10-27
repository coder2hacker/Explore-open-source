n=3
for x in range(1,11):
	print(n,"X",x,"=",(n*x))
print()
n=4
i=1

while i<=10:
	print(n,'X',i,'=',n*i)
	i+=1

#Usage of break: If the loop terminates in atleast two ways which are sufficiently different
#and requires substantially different processing then consider the use of termination via break for one of them

#Continie is used to skip one iteration from a loop , the loop is not exited

def greet_user(username):
	"""Display a simple greeting"""
	print("Hello",username)
greet_user('Shaurya')


def describe_pet(animal_type,pet_name):
	"""Display info about a pet"""
	print(f"\nI have a {animal_type}.")
	print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet('cat','boo')
describe_pet('dog','raju')

#Keyword-argument is a name value pair
def describe_pet(animal_type,pet_name):
	"""Display info about a pet"""
	print(f"\nI have a {animal_type}.")
	print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet(animal_type='cat',pet_name='boo')
describe_pet(animal_type='dog',pet_name='raju')

#Default Values: If arg is not given to a function then it uses these values
def describe_pet(pet_name,animal_type='dog'):       
	"""Display info about a pet"""
	print(f"\nI have a {animal_type}.")
	print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet(animal_type='cat',pet_name='boo')
describe_pet('boo','cat')
describe_pet('raju')
#describe_pet()   Error
print()

def make_shirt(size,print_text):
	print(f"Size={size} inches")
	print(f"{print_text} will be printed")
make_shirt(40,'\'Nirlajj\'')
print()
#Return value of the function

def get_formatted_name(first_name,last_name,middle_name=''):
	"""Return a full name, neatly formatted"""
	full_name = f"{first_name} {middle_name} {last_name}"
	return full_name.title()
musician=get_formatted_name('ravi','shankar','k')
print(musician)

#Returning a dictionary
def  build_person(first_name,last_name,age=None):
	"""Return a dict of info about a person"""
	person={'first':first_name.title(),'last':last_name.title()}
	if age:
		person['age']=age
	return person
musician=build_person('ravi','Shankar',27)
print(musician)

#passing a list to a function
def greet_users(names):
	"""Print a simple greeting to each user within list"""
	for name in names:
		msg=f"Hello, {name.title()}"
		print(msg)

usernames = ['Dhruv','Ruhi','Sneha']
greet_users(usernames)

#New example
unprinted_designes= ['phone case','robot pendant','cube']
completed_models=[]

#Simulate printing each design, until none are left
#Move each design to completed_models after printing
while unprinted_designes:
	current_design=unprinted_designes.pop()
	print(f"Printing model: {current_design.title()}")
	completed_models.append(current_design)

#Display all completed models
print("\nThe following models have been printed:")
for completed_model in completed_models:
	print(completed_model)
print()

def print_models(unprinted_designes,completed_models):
	"""Simulate printing each design, until none are left.
	Move each design to completed_models after printing
	"""
	while unprinted_designes:
	current_design=unprinted_designes.pop()
	print(f"Printing model: {current_design.title()}")
	completed_models.append(current_design)

def show_completed_models(completed_models):
	"""Show all the models that were printed"""
	print("\nThe following models have been printed:")
for completed_model in completed_models:
	print(completed_model)

unprinted_designes=['phone case','robot pendant','cube']
completed_models=[]

print_models(unprinted_designes,completed_models)
show_completed_models(completed_models)
print()

def get_formatted_name(first_name,last_name):
	"""Return a full name, neatly formatted"""
	full_name = f"{first_name} {last_name}"
	return full_name.title()

while True:
	print("\nPlease enter your name:")
	print("(enter q at any time to quit)")

	f_name=input("First Name: ")
	if f_name=='q':
	    break

	l_name=input("last name: ")
	if l_name=='q':
		break

	formatted_name=get_formatted_name(f_name,l_name)
	print(f"\n Hello, {formatted_name}")

















