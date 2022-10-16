# Q-1  Nearest greater to right.py


class Solution:
    def nextLargerElement(self, arr, n):

        stack = []
        ans = []
        for i in range(n-1, -1, -1):
            if len(stack) == 0:
                ans.append(-1)
            elif len(stack) > 0 and stack[-1] > arr[i]:
                ans.append(stack[-1])
            elif len(stack) > 0 and stack[-1] < arr[i]:

                while (len(stack) != 0 and stack[-1] <= arr[i]):
                    stack.pop()

                if len(stack) == 0:
                    ans.append(-1)
                else:
                    ans.append(stack[-1])
            stack.append(arr[i])
        return ans[::-1]



#Q-2 Stock span problem.py

class Solution:

    #Function to calculate the span of stockâ€™s price for all n days.
    def calculateSpan(self,arr,n):
        s=[]
        ans= []

        for i in range (0,n):


            if len(s)==0:
                ans.append(-1)
            elif (len(s)>0 and s[-1][0]>arr[i]):
                ans.append(s[-1][1])
            elif (len(s)>0 and s[-1][0]<arr[i]):
                while (len(s)!=0 and s[-1][0]<arr[i]):
                    s.pop()
                if len(s)==0:
                    ans.append(-1)
                else:
                    ans.append(s[-1][1])
            s.append([arr[i],i])


        for i in range (n):
            ans[i]=i-ans[i]
        return ans

  # Q-3 Maximum Rectangular Area in a Histogram.py

  class Solution:
    def largestRectangleArea(self, arr: List[int]) -> int:
        n=len(arr)
        def right(arr):
            n=len(arr)
            stack =[]
            ans = []
            index=n
            for i in range (n-1,-1,-1):
                if len(stack)==0:
                    ans.append(index)
                elif len(stack)>0 and stack[-1][0] < arr[i]:
                    ans.append(stack[-1][1])
                elif len(stack)>0 and stack[-1][0] >= arr[i]:

                    while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                        stack.pop()

                    if len(stack)==0:
                        ans.append(index)
                    else:
                        ans.append(stack[-1][1])
                stack.append([arr[i],i])
            return ans[::-1]

        def left(arr):
            n=len(arr)
            stack =[]
            ans = []

            for i in range (0,n):
                if len(stack)==0:
                    ans.append(-1)
                elif len(stack)>0 and stack[-1][0] < arr[i]:
                    ans.append(stack[-1][1])
                elif len(stack)>0 and stack[-1][0] >= arr[i]:

                    while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                        stack.pop()

                    if len(stack)==0:
                        ans.append(-1)
                    else:
                        ans.append(stack[-1][1])
                stack.append([arr[i],i])
            return ans
        Left= left(arr)
        Right= right(arr)
        width=[]
        area=[]
        for i in range (n):
            width.append(Right[i]-Left[i]-1)
            area.append(width[i]*arr[i])
        return max(area)



  Q-4 Max area rectangle in Binary matrix.py

  class Solution:
    def maximalRectangle(self, arr: List[List[str]]) -> int:
        n=len(arr)
        m=len(arr[0])
        def mah(arr):
            n=len(arr)
            stack =[]
            ans1 = []
            index=n
            for i in range (n-1,-1,-1):
                if len(stack)==0:
                    ans1.append(index)
                elif len(stack)>0 and stack[-1][0] < arr[i]:
                    ans1.append(stack[-1][1])
                elif len(stack)>0 and stack[-1][0] >= arr[i]:
                    while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                        stack.pop()

                    if len(stack)==0:
                        ans1.append(index)
                    else:
                        ans1.append(stack[-1][1])
                stack.append([arr[i],i])
            ans1= ans1[::-1]
            stack =[]
            ans2 = []

            for i in range (0,n):
                if len(stack)==0:
                    ans2.append(-1)
                elif len(stack)>0 and stack[-1][0] < arr[i]:
                    ans2.append(stack[-1][1])
                elif len(stack)>0 and stack[-1][0] >= arr[i]:
                    while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                        stack.pop()
                    if len(stack)==0:
                        ans2.append(-1)
                    else:
                        ans2.append(stack[-1][1])
                stack.append([arr[i],i])
            ans  = -100000000000
            for i in range (n):
                ans = max(ans,((ans1[i]-ans2[i]-1)*arr[i]))
            return ans    

        v=[]
        for  i in range (m):
            v.append(int(arr[0][i]))
        mx = mah(v)
        for i in range (1,n):
            for j in range (m):
                if arr[i][j]=='0':
                    v[j]=0
                else:
                    v[j]=v[j]+int(arr[i][j])
            mx = max(mx,mah(v))
        return mx

  Q-5 The celebrity Problem.py


class Solution:

    #Function to find if there is a celebrity in the party or not.
    def celebrity(self, M, n):
        ans = -1
        for i in range (n):

            if 1 in M[i]:
                pass
            else:
                ans=i

        if ans == -1:
            return -1
        if ans+1 == n:
            for  i in range (ans-1, -1 , -1):
                if 1 not in M[i]:
                    return -1
                else:
                    pass
        for j in range (ans, n):
            if 1 in M[i]:
                pass
            else:
                return -1

        return ans

 #Q-6 Maximum of minimum for every window size.py


def maxmin_window(arr):

        n=len(arr)
        stack =[]
        ans1 = []
        index=n
        for i in range (n-1,-1,-1):
            if len(stack)==0:
                ans1.append(index)
            elif len(stack)>0 and stack[-1][0] < arr[i]:
                ans1.append(stack[-1][1])
            elif len(stack)>0 and stack[-1][0] >= arr[i]:
                while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                    stack.pop()

                if len(stack)==0:
                    ans1.append(index)
                else:
                    ans1.append(stack[-1][1])
            stack.append([arr[i],i])
        ans1= ans1[::-1]
        stack =[]
        ans2 = []

        for i in range (0,n):
            if len(stack)==0:
                ans2.append(-1)
            elif len(stack)>0 and stack[-1][0] < arr[i]:
                ans2.append(stack[-1][1])
            elif len(stack)>0 and stack[-1][0] >= arr[i]:
                while (len(stack) !=0 and stack[-1][0] >= arr[i]):
                    stack.pop()
                if len(stack)==0:
                    ans2.append(-1)
                else:
                    ans2.append(stack[-1][1])
            stack.append([arr[i],i])

        ans = [0] * (n + 1)
        for i in range(n + 1):
            ans[i] = 0

        for i in range(n):
            Len = ans1[i] - ans2[i] - 1
            ans[Len] = max(ans[Len], arr[i])
        for i in range(n - 1, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])
        ans.pop(0)
        return ans
