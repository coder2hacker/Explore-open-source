dict={}
print(dict)
print(type(dict))
dict1={1:"rushi",2:"rushikesh",3:"thakare",5:[1,2,3,4]}
for i in dict1:
    print(i)
for i in dict1.values():
    print(i)
for i,j in dict1.items():
    print(i,j)

for i,j in dict1.items():
    print("%s scored %s"%(i,j))

print(dict1)
print(dict1[5])
#dictionary as tuple as a key 
dict2={(1,2,3,4,5):"abcd"}
print(dict2[(1,2,3,4,5)])
dict3={x:x*x*x for x in range(11)}
print(dict3[5])
dict4={x:2*x for x in range(11) if x%2==0}
print(dict4)
print(dict4.clear()) #remove all element of dictionary 
print(dict3.copy())

print(dict1.get(2))
print(dict1.setdefault(3))
print(len(dict1))
print(str(dict1))
print(all(dict1))
print(any(dict1))
print(sorted(dict1))

ans=[1,2,3,4,5,6,7,8,9,10]
res=["jan","feb","march","april","may","june","july","august","sep","oct"]
ans=zip(ans,res)
print(ans)
m_d=dict(ans)
print(m_d)
