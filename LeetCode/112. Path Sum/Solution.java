class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        sum = sum - root.val;
        if(root.left==null && root.right==null){
            if(sum == 0)return true;
            else return false;
        }
        return hasPathSum(root.left,sum) || hasPathSum(root.right,sum);
    }  
}
