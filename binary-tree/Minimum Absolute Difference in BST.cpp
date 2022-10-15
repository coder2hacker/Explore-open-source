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
    void f(TreeNode* root,vector<int>&v){
        if(root== NULL){
            return;
        }
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
        
    }   
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        f(root,v);
        int mini = INT_MAX;
        sort(v.begin(),v.end());
        for(int i =1 ; i<v.size();i++){
            int k = v[i]-v[i-1];
            mini = min(abs(k),mini);
            
        }
        return mini;
       
    }
};