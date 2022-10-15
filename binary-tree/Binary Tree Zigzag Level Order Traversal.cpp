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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>v(size);
            for(int i =0 ; i<size; i++){
                TreeNode*frontnode = q.front();
                q.pop();
                if(flag == true){
                    int index = i;
                    v[index]=frontnode->val;
                }
                else{
                    int index = size -i-1;
                    v[index]= frontnode->val;
                }
                
                if(frontnode->left != NULL){
                    q.push(frontnode->left);
                }
                if(frontnode->right != NULL){
                    q.push(frontnode->right);
                }
                
            }
            flag = !flag;
            res.push_back(v);
            
        }
        return res;
    }
};