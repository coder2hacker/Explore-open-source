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
public:
    void Postorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        Postorder(root->left,ans);
        Postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        Postorder(root,ans);
        return ans ;
        
        
    }
};