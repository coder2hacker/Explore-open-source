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
    pair<bool,int>isBalanced2(TreeNode* root){
        if(root == NULL){
            pair<bool,int>p;
            p.first = true;
            p.second = 0;
            return p;
        }
        pair<bool,int> left = isBalanced2(root->left);
        pair<bool,int> right = isBalanced2(root->right);
        pair<bool,int> ans ;
        ans.second = max(left.second, right.second)+1;
        ans.first= (abs(left.second - right.second)<=1) && left.first && right.first;
       
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root== NULL){
            return true;
        }
          pair<bool,int>z = isBalanced2(root);
        return z.first;
    
        
        
        
        
    }
};