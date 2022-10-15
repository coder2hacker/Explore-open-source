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
    bool hasPathSum(TreeNode* root, int k) {
      if(root==NULL ){
              return false;
          }   
      if(root->left == NULL && root->right==NULL){
          if(k-root->val ==0){
              return true;
          }
          else{
              return false;
          }
      }
      
     k-= root->val;
     bool left = hasPathSum(root->left, k);
     bool right = hasPathSum(root->right, k);
     k+=root->val;
        
        
     return left|| right;
          
      
    }
};