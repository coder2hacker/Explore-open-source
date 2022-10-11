n,d = map(int,input().split())
arr=list(map(int,input().split()))

for i in range(d):
    first=arr[0]
    for j in range(n-1):
        arr[j]=arr[j+1]
    arr[n-1]=first 
print(*arr,sep=" ")