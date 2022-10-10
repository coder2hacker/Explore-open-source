 bt=[2,4,1,4,6,5]
n=len(bt)
priority=[5,3,2,1,3,4] # 1 is lowest 5 highest
prio=priority.copy()
d={} #d={priority:[process numbers]}
for i in range(n):
    if priority[i] in d:
        d[priority[i]].append(i+1)
    else:
        d[priority[i]]=[i+1]
gantt= {}
ct=0
p=list(set(priority))
for i in p[::-1]:
    for j in d[i]:
        gantt[j]=bt[j-1]+ct
        ct+=bt[j-1]
tot_tat=tot_wt=0
print("P\tAT\tPri\tBT\tCT\tTAT\tWT")
for i in range(n):
    tat=CT=gantt[i+1]
    tot_tat+=tat
    wt=tat-bt[i]
    tot_wt+=wt
    print(i+1,0,prio[i],bt[i],CT,CT,wt,sep='\t')
print("Average TAT = ",tot_tat/n)
print("Average WT = ",tot_wt/n)
print("Throughput = ",n/ct)
 n=input("Enter Preemptive or Non-Preemptive")
lock=0
def p1():
    global lock
    print("Entry Section of P1")
    lock=1
    print("Lock value is",lock)
    print("Critical Section of P1")
    if n=="Non-Preemptive":
        print("Exit Section of P1")
        lock=0
        print("Lock value is",lock)
    else:
        pass
def p2():
    global lock
    print("Entry Section of P2")
    lock = 1
    print("Lock value is", lock)
    print("Critical Section of P1")
    print("Exit Section of P1")
    lock = 0
    print("Lock value is", lock)
p1()
p2()
 case=input("Enter Preemptive or Non-Preemptive ")
c = 0
s = 1
l = []
def Up(n):
    global c
    global s
    global l
    if s == 0 or s == 1:
        print("Process",n,"Completed")
        l.pop(0)
    else:
        pass
def Down(n):
    global c
    global l
    global s
    l.append
    print("The queue is", l[1::])
    if s == 1:
        s = 0
    else:
        pass
if case == "Preemptive":
    Down(1)
    Down(2)
    Down(3)
    Up(1)
    Up(2)
    Up(3)
elif case == "Non-Preemptive":
    Down(1)
    Up(1)
    Down(2)
    Up(2)
    Down(3)
    Up(3)