// https://leetcode.com/problems/combination-sum/

class Solution {
	public List<List<Integer>> combinationSum(int[] nums, int target) {
		List<List<Integer>> ans = new ArrayList<>();
		findSum(nums,target,0,new ArrayList<Integer>(),ans);
		return ans;
	}

  void findSum(int[] nums,int target, int ind,ArrayList<Integer> al,  List<List<Integer>> ans)
  {
      if(ind==nums.length){
          if(target==0)
          {
              ans.add(new ArrayList<>(al));
              return;
          }
          return;
      }

      if(nums[ind]<=target)
      {
          al.add(nums[ind]);
          findSum(nums,target-nums[ind],ind,al,ans);
          al.remove(al.size()-1);
      }
      findSum(nums,target,ind+1,al,ans);
  }
}
