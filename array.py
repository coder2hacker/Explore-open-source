import array as arr 

a=arr.array('i',[1,2,3])
print(a) 

for i in range(0,3):
    print(a[i],end=" ") 
print() 

b=arr.array('d',[2.5,3.5,4.5])

for i in range(0,3):
    print(b[i],end=" ") 
print()
a.insert(1,4)
print(a)

a.append(0)
print(a)

print(a[0])

a.pop(2)
a.remove(1)
print(a) 

slice_array = a[0:3]
print(slice_array) 

ans=a.index(1)
print(ans)

ans=arr[4]



