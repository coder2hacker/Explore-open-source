#python program to find arm strong number

num = int(input("enter the number:"))
temp = str(num)
num_len = len(temp)
arr = []
for i in temp:
    arr.append(int(i) ** num_len)
if num == sum(arr):
    print("arm strong")
else:
    print("not arm strong")
