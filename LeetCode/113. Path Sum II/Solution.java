class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> currentPath = new ArrayList();
        List<List<Integer>> allPaths = new ArrayList();
        findPathsRecursive(root,targetSum,currentPath,allPaths);
        return allPaths;
    }
    private static void findPathsRecursive(TreeNode currentNode, int sum, List<Integer> currentPath,List<List<Integer>> allPaths){
         if(currentNode==null)return;
         // add the current node to the path
         currentPath.add(currentNode.val);
         // if the current node is a leaf and its value is equal to sum, save the current path
         if(currentNode.val==sum && currentNode.left==null && currentNode.right==null)
             allPaths.add(new ArrayList<Integer>(currentPath));
         else{
             // traverse the left sub-tree
             findPathsRecursive(currentNode.left,sum-currentNode.val,currentPath,allPaths);
             // traverse the right sub-tree
             findPathsRecursive(currentNode.right,sum-currentNode.val,currentPath,allPaths);
         }
         // remove the current node from the path to backtrack, 
         // we need to remove the current node while we are going up the recursive call stack.
         currentPath.remove(currentPath.size()-1);
      }

}
