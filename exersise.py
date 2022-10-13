main_num=19
ct=0
while(True):
    i=int(input("ENter the number: "))
    if(i==main_num):
        print("congratulation , you choose right no..")
        print("you have take ",ct+1," chance for guessing the value")
        break
    elif(i<main_num):
        print("inc your no")
        ct=ct+1
    else:
        print("dec your no")
        ct=ct+1