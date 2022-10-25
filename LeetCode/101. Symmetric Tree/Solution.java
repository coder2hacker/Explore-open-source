class Solution {
    public boolean isSymmetric(TreeNode root) {
       return root == null || isMirror(root.left, root.right);
    }
    boolean isMirror(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) return true;
        
        if (node1 == null || node2 == null) return false;
        
        if (node1.val != node2.val) return false;
        return isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);
    }
}
