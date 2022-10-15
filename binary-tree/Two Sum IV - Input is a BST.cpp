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
    //fill vector in sorted order 
    void fill(  vector<int> &v , TreeNode* root){
        if(root==NULL){
            return;
        }
        fill(v,root->left);
        v.push_back(root->val);
        fill(v,root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        vector<int>v;
        fill(v,root);
        int i = 0;
        int j = v.size()-1;
        
        while(i<j){
            int f=(v[i]+v[j]); 
            if(f==k){
                return true;
            }
            else if( f<k){
                i++;
            }
            else {
                j--;
            }
            
        }
        
        return false;
    }
};