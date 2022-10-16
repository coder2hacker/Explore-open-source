// https://leetcode.com/problems/first-missing-positive/

class Solution {
    public int firstMissingPositive(int[] nums) {
     int ln=nums.length;
    HashMap<Integer,Integer> hs=new HashMap<>();
        for(int i=0;i<ln;i++)
        {
            hs.put(nums[i],1);
        }
        for(int i=1;;i++)
        {
            if(hs.get(i)==null)
            {
                return i;
            }
        }
  }
}
