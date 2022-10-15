#Bubble sort for user input.

def bubble_sort(L):
    t=len(L)
    for i in range(len(L)-1):
        for j in range(t-1):
            if L[j]>L[j+1]:
                L[j],L[j+1]=L[j+1],L[j]
        t-=1
    print(L)

#__main()__
X=list(map(int,input().split()))
bubble_sort(X)