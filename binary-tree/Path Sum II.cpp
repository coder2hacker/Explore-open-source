/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> ans;
public:
    
    void helper(TreeNode* root, int& currSum, int& targetSum, vector<int>& currPath) {
        
        if(!root)
            return;
        
        //add root->val to currSum and push root->val to currPath array
        currSum += root->val;
        currPath.push_back(root->val);
        
        //check if current node is leaf node and currSum == targetSum then push currPath into ans array
        if(!(root->left) && !(root->right) && currSum == targetSum) 
            ans.push_back(currPath);
        
        //recursive call to left sub-tree
        helper(root->left,currSum,targetSum,currPath);
        //recursive call to right subtree
        helper(root->right,currSum,targetSum,currPath);
        
        //move to previous state remove root->val from currSum and remove current root->val from currPath array
        currSum -= root->val;
        currPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currPath;
        int currSum = 0;
        helper(root,currSum,targetSum, currPath);
        return ans;
    }
};