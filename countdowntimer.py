import time

def countdown(t):
    while t:
        mins, secs = divmod(t, 60)
        timeformat = '{:02d}:{:02d}'.format(mins, secs)
        print(timeformat, end='\r')
        time.sleep(1)
        t -= 1
    print('Time Up!!\n\n\n\n\n')

t=int(input("Enter Time for Cout Down(in Sec) :- "))
countdown(t)