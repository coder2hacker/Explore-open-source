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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,map<int,vector<int>>>m;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>>temp = q.front();
            q.pop();
            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int lv = temp.second.second;
            m[hd][lv].push_back(front->val);
            if(front->left){
                q.push(make_pair(front->left,make_pair(hd-1,lv+1)));
            }
            if(front->right){
    q.push(make_pair(front->right,make_pair(hd+1,lv+1)));
            } 
        }
       for(auto i:m){
        vector<int>ans;
        for(auto j:i.second){
             sort(j.second.begin(), j.second.end());
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
        res.push_back(ans);
    }
       return res; 
        
    }
};