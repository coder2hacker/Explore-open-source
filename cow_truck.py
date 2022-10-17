# current fuel <= 10^6  -->p
# fuel station <= 10^5  -->n
#distance = l

l = int(input("Enter the distance between jungle to town:"))
n = int(input("Enter the number of fuel station:"))
p = int(input("Enter the intial fuel :"))

#dftts= distance from town to station
# dftts1 = 4,dftts2 = 5,dftts3 = 11,dftts4 = 15
# town-4-s1-1-s2-6-s3-4-s4-10-truck
s = 0 #number of stops
f=[10,5,2,4]  #unit of fuel at s4-s3-s2-s1
x=[10,4,6,1,4]  #distance between truck-s4-s3-s2-s1-town
for i in range(0,n):
    p = p - x[i]
    # print(p)
    if p < x[i+1]:
        # print("stop the truck")
        p = p + f[i]
        s = s + 1
    i = i + 1
print(s)