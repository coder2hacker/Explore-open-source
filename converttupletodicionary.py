#python program to convert tuple to dictionary 
#create a tuple
tuplex = ((2, "w"),(3, "r"))
print(dict((y, x) for x, y in tuplex))