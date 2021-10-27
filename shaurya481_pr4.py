alien_0={'color':'green','points':5}
alien_1={'color':'yellow','points':10}
alien_2={'color':'red','points':15}
aliens=[alien_0,alien_1,alien_2]
for alien in aliens:
	print(alien)

#Make an empty list for storing aliens
aliens=[]
for alien_number in range(30):
	new_alien={'color':'green','points':5,'speed':'slow'}
	aliens.append(new_alien)

#print the first 5 aliens
for alien in aliens[:5]:
	print(alien)
print()

#How many aliens have been created?
print(f"Total number of aliens: {len(aliens)}\n")
#Editing features of the alien within loop
for alien in aliens[:3]:
	if alien['color']=='green':
		alien['color']='yellow'
		alien['speed']='medium'
		alien['points']=10
for alien in aliens[:5]:
	print(alien)
print()

#Its convinient to store info about the same thing containing many parameters
pizza={
	'crust':'thick',
	'toppings':['mushroom','extra cheese'],
}

#Summarize the order
print(f"You ordered a {pizza['crust']}-crust pizza ""with the following toppings:")
for topping in pizza['toppings']:
	print('\t'+topping)
print()
fav_lang={
	'jen':['python','ruby'],
	'sara':['c'],
	'edward':['ruby','go'],
	'phil':['ocaml','swift'],
}

for name,language in fav_lang.items():
	print(f"Favorite language of {name.title()} is:")
	for lang in language:
		print("\t",lang)
print()

#Dictionary inside Dictionary
users={
	'aeinstein':{
	'first':'albert',
	'last':'einstein',
	'location':'princeton',
	},
	'mcurue':{
	'first':'marie',
	'last':'curie',
	'location':'paris',
	},
}

for uid,info in users.items():
	print(f"\nUsername:{uid}")
	full_name=f"{info['first']} {info['last']}"
	location=info['location']

	print(f'\tFull Name :{full_name.title()}')
	print(f'\tLocation: {location.title()}')
print()

print(len(users))
print(users.keys())
print(users.values())








