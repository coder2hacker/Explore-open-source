from tkinter import *
root= Tk()
root.geometry("1360x600")
global mylabel,mybutton_1,mybuttton_2,mylabel_2,emp,head1,head2,head3,head4,head5

mybutton_1=Button(root,text="Play Again",padx=12,pady=12,fg="yellow",bg="black")

mybutton_2=Button(root,text="Home",padx=12,pady=14,fg="yellow",bg="black")

mybutton_1.place(anchor=CENTER,relx=0.9,rely=0.1)

mybutton_2.place(anchor=CENTER,relx=0.1,rely=0.1)

head1 = Label(root, text="CONGRATULATION !!  YOU WIN ", width="45", font=("bold", 34),fg="green")
head1.place(anchor=CENTER, relx=0.5, rely=0.2)
head2=Label(root,text="Score Board :-" ,width="30",font=("bold",28),fg="red")
head2.place(anchor=CENTER,relx=0.2,rely=0.4)

head3=Label(root,text="Player1 :",width="30",font=("bold",20),fg="red")
head3.place(anchor=CENTER,relx=0.3,rely=0.5)
head4=Label(root,text="Player2 :",width="30",font=("bold",20),fg="red")
head4.place(anchor=CENTER,relx=0.3,rely=0.6)
head5=Label(root,text="WINNER :",width="40",font=("bold",30),fg="red")
head5.place(anchor=CENTER,relx=0.5,rely=0.7)
emp=Label(root,print("U+1F600"),width="10")
emp.place(anchor=CENTER,relx=0.2,rely=0.2)

root.mainloop()
