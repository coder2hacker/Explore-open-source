def add(a,b):
  return a+b 
def sub(a,b):
  return a-b 
def mul(a,b):
  return a*b
def div(a,b):
  return a/b 
  
while True:
  a=float(input("Enter first digit"))
  b=float(input("Enter second digit"))
  op=input(" enter 1 for add 2 for sub 3 for mul 4 for div ")
  
  if op=="1":
    print(add(a,b))
  elif op=="2":
    print(sub(a,b))
  elif op=="3":
    print(mul(a,b))
  elif op=="4":
    print(div(a,b))
  else:
    print("Plz select correct option")
    
    
  cond=input("Do u wanna continue(Yes/No)")
  if cond.lower()=="Yes":
    continue
  elif cond.lower()=="No":
    break
  else :
    print("")