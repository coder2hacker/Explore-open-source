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
    void levelorder(TreeNode* root, vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        v.push_back(root->val);
        ans.push_back(v);
         vector<int>n;
        while(!q.empty()){
            TreeNode*temp = q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(n);
                n.clear();
               
              
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                    n.push_back(temp->left->val);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    n.push_back(temp->right->val);
                }
            }
        }
        ans.pop_back();
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        levelorder(root,ans);
       return ans ; 
        
    }
};