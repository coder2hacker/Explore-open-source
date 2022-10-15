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
   void f(TreeNode* root,vector<vector<int>>&v,vector<int>&c){
       if(root==NULL){
           return ;
       }
       if(root->left == NULL && root->right == NULL){
           c.push_back(root->val);
           v.push_back(c);
           return;
       }
       c.push_back(root->val);
       if(root->left){
       f(root->left,v,c);
         c.pop_back(); 
       }
       if(root->right){
       f(root->right,v,c);
        c.pop_back();
       }
      
         
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string>d;
        if(root==NULL){
            d.push_back(s);
            return d;
        }
        vector<vector<int>>v;
        vector<int>c;
        f(root,v,c);
        for(auto i : v){
            string s ="";
            int count=0;
            for(auto j :i){
                s+=to_string(j);
                cout<<j<<" ";
                if(count!=i.size()-1){
                s+="->";
                }
                count++;
            }
           
            d.push_back(s);

        }
      
        
        return d;
    }
};