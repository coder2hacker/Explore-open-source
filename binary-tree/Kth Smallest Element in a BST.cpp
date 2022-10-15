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
   void solve(TreeNode* root, int k,int &i, int &ans){
        if(root == NULL){
            return ;
        }
        solve(root->left, k,i,  ans);
         i=i+1;
        if(i==k){
            ans = root->val;
            return ;
        }
        solve(root->right, k,i,  ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i =0;
        int ans;
        solve(root , k , i, ans);
        return ans ;
    }
};