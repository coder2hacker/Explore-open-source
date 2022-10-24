class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        
        List<Integer> list= new ArrayList<Integer>();
        if(root==null){
            return list;
        }
        return inorder(list,root);
        
    }
    
    public List inorder(List list, TreeNode root){
        if(root==null){
            return list;
        }
        inorder(list,root.left);
        list.add(root.val);
        inorder(list,root.right);
        return list;
    }
}
