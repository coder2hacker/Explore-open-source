#Program to remove the I-th occurence of given word in a list where words repeat

def removeWord(list,word,O):
    count=0
    newList=[]

    for i in list :
        if(i==word):
            count=count-1
            if(count!=S):
                newList.append(i)
        else:
            newList.append(i)

    list=newList

    if(count==0):
        print("Item not found")
    else:
        print("Updated List is :", list)


n=int(input("Enter the number of element in list:"))
list=[]

for i in range (n):
    ele=input("Enter element:")
    list.append(ele)

word=input("Enter the word to remove:")
S=int(input("Enter the occurence of word to remove :"))

removeWord(list,word,S)
