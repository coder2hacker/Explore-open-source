// https://leetcode.com/problems/minimum-window-substring/

class Solution {
    public String minWindow(String s, String t) 
    {
        if(s.length() == 0 || t.length() == 0)
            return "";
        HashMap<Character,Integer> map = new HashMap<>();
        int n = s.length(),m=t.length();
        
        for(int i=0; i<m;i++)
            map.put(t.charAt(i) , map.getOrDefault(t.charAt(i), 0)+1);
			
        int count = map.size();
        int start =0,end =0,min =Integer.MAX_VALUE;
        String substring = "";
        
        while(end < n)
        {
            char ch = s.charAt(end);
            if(map.containsKey(ch))
            {
                map.put(ch , map.get(ch) -1);
                if(map.get(ch) == 0)
                    count--;
            }
            if(count > 0)
                end++;
				
            else if(count == 0)
            {
                while(count == 0)
                {
                    if(end-start +1 < min)
                    {
                        min = end-start+1;
                        substring = s.substring(start,end+1);
                    }
                    char temp = s.charAt(start);
                    if(map.containsKey(temp))
                    {
                        map.put(temp , map.get(temp)+1);
                        if(map.get(temp) == 1)
                           count++;
                    }
                    start++;
                }
                end++;
            }
        }
        return substring;     
    }
}
