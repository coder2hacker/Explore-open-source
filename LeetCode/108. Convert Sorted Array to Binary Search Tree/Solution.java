class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return Create(nums,0,(nums.length-1));
    }
    public static TreeNode Create(int[] nums,int st,int end){
        if(st>end){
            return null;
        }
        int mid = (st+end)/2;
        
        TreeNode root = new TreeNode(nums[mid]); // mid becomes root
        
        root.left=Create(nums,st,mid-1); // for left subtree mid of remaining left becomes left child of main root
        
        root.right=Create(nums,mid+1,end); // for right subtree mid of remaining right becomes right child of main root
        
        return root;
    }
}
