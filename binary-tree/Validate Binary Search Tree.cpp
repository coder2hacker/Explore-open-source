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
    bool vali(TreeNode* root, long long  lf , long long  rr){
        if(root==NULL){
            return true;
        }
        if(root->val >=rr || root->val<=lf ){
            return false;
        }
        bool l = vali(root->left , lf, root->val);
        bool r = vali(root->right , root->val ,rr);
        return l&&r;
    
    }
   
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left == NULL && root->right==NULL){
            return  true;
        }
       return vali(root , LLONG_MIN,LLONG_MAX);
    }
};