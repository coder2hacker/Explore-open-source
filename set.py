s = {1,2,2,3,4}
print(s)
#s1 = {{1,2},{3,4}}
s1 = {frozenset({1,2}),frozenset({3,4})}
print(s1)
#print(type(s))
b = {3,3,4,4,5}
print(b)

#intersection 
print(s.intersection(b))
print(s&b)

#union 
print(s.union(b))
print(s|b)

