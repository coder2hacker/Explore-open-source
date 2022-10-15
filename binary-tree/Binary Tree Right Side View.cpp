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
    void f(TreeNode* root,vector<int>&v, int lev){
        if(root==NULL){
            return ;
        }
        if(v.size()==lev){
            v.push_back(root->val);
        }
        
        f(root->right,v,lev+1);
        f(root->left,v,lev+1); 
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int lev =0;
        f(root,v, lev);
        return v;
    }
};