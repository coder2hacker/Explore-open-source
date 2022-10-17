class Solution:
    def trap(self, height: List[int]) -> int:
      
      
      
      #Method 1 to slove the problem 
      #time comp :- O(N)
      #space comp :- O(N)
        n=len(height)
        lmax=[]
        lmax.append(height[0])
        for i in range (1,len(height)):
            lmax.append(max(height[i],lmax[-1]))
        
        rmax=[]
        rmax.append(height[-1])
        for i in range (len(height)-2,-1,-1):
            rmax.append(max(height[i],rmax[-1]))
        rmax=rmax[::-1]
        
        ans=0
        
        for i in range (n):
            ans+=(abs(min(rmax[i],lmax[i])-height[i]))
        return ans
        
        

      #Method 2 to slove the problem 
      #time comp :- O(N)
      #space comp :- O(N)
      
        if len (height )<=2:
            return 0
        
        rmax=height [-1]
        lmax=height[0]
        
        i=1
        j=len(height)-1
        ans=0
        while (i<=j):
            if height[i]>lmax:
                lmax=height[i]
            if height[j]>rmax:
                rmax=height[j]
            
            if rmax >= lmax:
                ans +=lmax-height[i]
                i+=1
            else:
                ans += rmax - height[j]
                j -= 1
        
        return ans
 
