#Allowed char for a password are:- "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~0123456789"


import string
import random
characters = string.ascii_letters + string.punctuation  + string.digits

password = ""
password_length = random.randint(8, 16)

for x in range(password_length):
    char = random.choice(characters)
    password = password + char

print(password)


