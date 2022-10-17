strings="hii how are you"
print(strings)
# how to slice the given string 
print(len(strings))
print(strings[0:5:2])
#print(strings[-4:-1])

#how to check whether the string is alphanumeric or not...
# alphanumeric==alphabets+numbers without space.......
print(strings.isalnum())  #it gives false... because it contain spaces..between two letters.
a="kunal"
print(a.isalnum()) #it gives true value... a string does not contain any space..

print(strings.isalpha()) #it gives false because it contain spaces/number...

print(a.isalpha()) #it returns true because string a does not contain any spaces/num...
