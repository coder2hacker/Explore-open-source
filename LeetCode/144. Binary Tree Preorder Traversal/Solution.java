class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
     ArrayList<Integer> ans = new ArrayList<Integer>();
      if(root == null) return ans;
      
      Stack<TreeNode> st = new Stack<TreeNode>();
      st.push(root);
      
      while(!st.isEmpty()) {
        TreeNode cur = st.pop(); 
        ans.add(cur.val);
        
          if(cur.right != null) st.push(cur.right);
          if(cur.left != null) st.push(cur.left);
      }
      return ans;
    }
}
