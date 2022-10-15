// https://leetcode.com/problems/roman-to-integer/

class Solution {
    public int romanToInt(String s) {
        
        Map<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        
        char prev = ' ';
        
        int ans = 0;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)=='I' && prev == 'V' || s.charAt(i)=='I' && prev == 'X'){
                ans-=1;
            }else if(s.charAt(i)=='X' && prev == 'L' || s.charAt(i)=='X' && prev == 'C'){
                ans-=10;
            }else if(s.charAt(i)=='C' && prev == 'D' || s.charAt(i)=='C' && prev == 'M'){
                ans-=100;
            }else{
                ans += map.get(s.charAt(i));
            }
            
            prev = s.charAt(i);
        }
        
        return ans;
    }
}
