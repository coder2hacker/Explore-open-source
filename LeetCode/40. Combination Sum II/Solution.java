// https://leetcode.com/problems/combination-sum-ii/

class Solution {
  public List<List> combinationSum2(int[] candidates, int target)
  {

      List<List<Integer>> ans = new ArrayList<>();
      List<Integer> a = new ArrayList<>();
      Arrays.sort(candidates);
      int i =0;
      int j = candidates.length;

      findCombinations(candidates, target, i,ans,a);

      return ans;

  }

  public void findCombinations(int[] candidates, int target, int index, List<List<Integer>> ans, List<Integer> a)
  {

      if(target == 0)
      {
          ans.add(new ArrayList<Integer>(a));
          return;
      }



       for(int i = index; i< candidates.length ; i++)
       {
          if(index!= i && candidates[i]==candidates[i-1])
              continue;

          if(candidates[i] <= target )
          {   
              a.add(candidates[i]);
              findCombinations(candidates,target-candidates[i],i+1,ans,a);
              a.remove(new Integer(candidates[i]));
          }
      }


  } 
}
