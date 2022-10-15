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
    bool isone(TreeNode* root){
        if(root==NULL){
            return false;
        }
        if(root->val == 1){
            return true;
        }
        
      bool l =  isone(root->left);
      bool r =  isone(root->right);
      return l||r;    
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
       if(isone(root)==false){
           return NULL;
       }
        bool left = isone(root->left);
        if(root != NULL &&  left == false){
            root->left = NULL;
        }
        else{
         root->left = pruneTree(root->left);
        }
        bool right = isone(root->right);
        if(root != NULL && right == false){
            root->right = NULL;
        }
        else{
         root->right = pruneTree(root->right);
        }
        
       return root;   
    }
};

//////////////////////////
















// bool New_Node(TreeNode* term)
// {
//     bool current=false, left, right;
    
//     if(term==NULL)
//     {
//         return false;
//     }
    
//     if(term->val==1)
//     {
//         current=true;
//     }
    
//     left=New_Node(term->left);
//     if(left==false)
//     {
//         term->left=NULL;
//     }
    
//     right=New_Node(term->right);
//     if(right==false)
//     {
//         term->right=NULL;
//     }
    
//     return (current | left | right);
// }

// class Solution {
// public:
//     TreeNode* pruneTree(TreeNode* root) {
        
//         bool check= New_Node(root);
        
//         // if final value returned by root node is false it means there was no "1" present in our binary tree           //so return NULL
//         if(check==false)
//         {
//             return NULL;
//         }
        
//         return root;
//     }
// };