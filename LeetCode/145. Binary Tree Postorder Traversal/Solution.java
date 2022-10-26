class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        // Create an array list to store the solution result...
        List<Integer> sol = new ArrayList<Integer>();
        // Return the solution answer if the tree is empty...
        if(root==null) return sol;
        // Create an empty stack and push the root node...
        Stack<TreeNode> bag = new Stack<TreeNode>();
        bag.push(root);
        // Loop till stack is empty...
        while(!bag.isEmpty()) {
            // set peek a node from the stack...
            TreeNode node = bag.peek();
            // If the subtrees of that node are null, then pop & store the pop value into solution result...
            if(node.left==null && node.right==null) {
                TreeNode pop = bag.pop();
                sol.add(pop.val);
            }
            else {
                // Push the right child of the popped node into the stack...
                if(node.right!=null) {
                    bag.push(node.right);
                    node.right = null;
                }
                // Push the left child of the popped node into the stack...
                if(node.left!=null) {
                    bag.push(node.left);
                    node.left = null;
                }
            }
        }
        return sol;     // Return the solution list...
    }
}
