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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        vector<int>ans ;
        q.push(NULL);
        int sum =0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(q.size()!=0){
                q.push(NULL);
                ans.push_back(sum); 
                    sum =0;
                }
                else{
                   ans.push_back(sum); 
                }
            }
            if(temp!=NULL){
                sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }  
            }  
        }
        return ans[ans.size()-1];
        
    }
};