class Solution { // TC: O(n), SC: O(height)
   int i, p; // i as index for inorder, p as index for preorder
   public TreeNode buildTree(int[] pre, int[] in) {
      i = p = 0;
      return dfs(pre, in, 3001);
   }

   private TreeNode dfs(int[] pre, int[] in, int rightBoundary) {
      if (p == pre.length || in[i] == rightBoundary) return null;

      TreeNode node = new TreeNode(pre[p++]);
      node.left  = dfs(pre, in, node.val);
      i++;
      node.right = dfs(pre, in, rightBoundary);
      return node;
   }
}
