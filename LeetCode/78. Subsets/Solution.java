// https://leetcode.com/problems/subsets/

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        //final ans
        List<List<Integer>> res= new ArrayList<>();
        //current subset
        List<Integer> list = new ArrayList<>();
        helper(0,nums,list,res);
        return res;
    }
 
    //we can either pick the current element or not pick
    public void helper(int index, int[] nums, List<Integer> list, List<List<Integer>> res){
        if(index >= nums.length)
            res.add(new ArrayList<>(list));
        else{
            //pick condition
            list.add(nums[index]);
            helper(index+1, nums, list, res);
            //backtracking to remove the last number
            list.remove(list.size()-1);
            //not pick condition
            helper(index+1, nums, list, res);
        }
    }
}
