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
    TreeNode* addOneRow(TreeNode* root, int val, int de) {
        if(root==NULL && de==1){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if( root==NULL){
            return NULL;
        }
        if(de==1 && root!= NULL){
          TreeNode* l = new TreeNode(val);
            l->left = root;
            return l;
        }
        if(de==2){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->right = NULL;
            r->left = NULL;
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
            return root;
        }
         root->left = addOneRow(root->left, val, de-1);
         root->right = addOneRow(root->right, val, de-1);
        return root;
    }
};