strs = ["eat","tea","tan","ate","nat","bat"] 
dict1={} 
for s in strs:
    x=''.join(sorted(s))
    print(x)
    if dict1.get(x): #return value of a given key 
        dict1[x].append(s)
    else:
        dict1[x]=[s] 
print(dict1.values())

