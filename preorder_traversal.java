/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> li = new ArrayList<>();
        preorder(root,li);
        return li;
    }
    
     public List<Integer> preorder(TreeNode root,List<Integer> li){
        if(root==null){
            return li;
        }
    
        li.add(root.val);
        preorder(root.left,li);
       preorder(root.right,li);
        
 
        return li;
    }
    
}
