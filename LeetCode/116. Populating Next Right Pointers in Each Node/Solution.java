class Solution {
    public Node connect(Node root) {
        if(root == null) return null;
        Node left = root.left;
        Node right = root.right;
        while(left != null){
            left.next = right;
            left = left.right;
            right = right.left;
        }
        connect(root.left);
        connect(root.right);
        return root;  
    }
}
