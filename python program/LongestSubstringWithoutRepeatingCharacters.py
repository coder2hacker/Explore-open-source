class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start=0
        end=0
        c=0
        ans=0
        a=set()
        for i in range(len(s)):
            while end<len(s) and (s[end] in a)!= True:
                a.add(s[end])
                end+=1
                c+=1
            ans=max(ans,c)
            c-=1
            a.remove(s[start])
            start+=1
        return max(c,ans)
sol = Solution()
s = "abcabcbb"
print(sol.lengthOfLongestSubstring(s))