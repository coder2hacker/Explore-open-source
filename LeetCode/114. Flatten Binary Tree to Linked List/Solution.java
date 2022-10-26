class Solution {
    ArrayList<Integer> list = new ArrayList<>();
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        getPre(root);
        TreeNode node = root;
        node.left = null;
        node.right = null;
        for(int i = 1; i < list.size() ; i++){
            node.right = new TreeNode(list.get(i));
            node = node.right;
        }
    }
    void getPre(TreeNode root){
        if(root == null){
            return;
        }
        list.add(root.val);
        getPre(root.left);
        getPre(root.right);
        
    }
    
}
