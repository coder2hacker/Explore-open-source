class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<>();
        }
        return helper(1, n);
    }
    
    private List<TreeNode> helper(int lo, int hi) {
        List<TreeNode> result = new ArrayList<>();
        //base case
        if (lo > hi) {
            result.add(null);
            return result;
        }
        
        //subproblem to reach boootm
        for (int i = lo; i <= hi; i++) {
            List<TreeNode> left = helper(lo, i - 1);
            List<TreeNode> right = helper(i + 1, hi);
            //reconstruct tree from bottom to up
            for (TreeNode l : left) {
                for (TreeNode r : right) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    result.add(root);
                }
            }
        }
        //return list of root to last layer
        return result;
    }
}
