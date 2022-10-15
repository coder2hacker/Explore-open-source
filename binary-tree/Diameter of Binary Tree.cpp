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
     pair<int,int> maxDepth(TreeNode* root) {
        if(root==NULL){
            pair<int,int>p;
             p.first =-1;
             p.second = 0;
            return p;
        }
        pair<int,int>op1 = maxDepth(root->left);
        pair<int,int>op2 = maxDepth(root->right);
        pair<int,int>ans ;
        ans.first = max(op1.first,op2.first)+1;
        int k =  op1.first + op2.first + 2;
        ans.second = max(op1.second , max(op2.second, k));
         
        return ans ;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        pair<int,int>p = maxDepth(root);
        // int op1 =diameterOfBinaryTree(root->left);
        // int op2 =diameterOfBinaryTree(root->right);
        // int op3 = maxDepth(root->left)+maxDepth(root->right)+2;
       
    
        return p.second;
        
    }
};