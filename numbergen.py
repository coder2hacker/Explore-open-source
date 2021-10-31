from tkinter import *
import random

def gen():
    num1 = int(entry1.get())
    num2 = int(entry2.get())
    out = random.randrange(num1, num2)
    output.config(text=out)

root = Tk()

global entry1, entry2, output

label1 = Label(root, text="Enter Minimum Range")
label2 = Label(root, text="Enter Maximum Range")
label1.grid(row=0, column=0, padx=10, pady=10)
label2.grid(row=1, column=0, padx=10, pady=10)

entry1 = Entry(root)
entry2 = Entry(root)
entry1.grid(row=0, column=1, padx=10, pady=10)
entry2.grid(row=1, column=1, padx=10, pady=10)
entry1.insert(END, '1')
entry2.insert(END, '100')

button1 = Button(root, text="Submit", command=gen)
button2 = Button(root, text="Close", command=lambda : quit())
button1.grid(row=2, column=0, padx=10, pady=10)
button2.grid(row=2, column=1, padx=10, pady=10)

output = Label(root, text="")
output.grid(row=3, column=0, columnspan=2)

root.mainloop()
