class Solution {
    int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        findMaxPathSum(root);
        return maxSum;
    }

    public int findMaxPathSum(TreeNode root) {
         if(root == null) return 0;   
         int left =   Math.max(0, findMaxPathSum(root.left));   //why compare with 0
        //if 3,-12,-2 so findmax =-12 instead of returning -12 return 0 so comp with 0
         int right =  Math.max(0, findMaxPathSum(root.right));        
         maxSum = Math.max(maxSum , left + right + root.val);
         return Math.max(left, right) + root.val;
    }
}
