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
    int findpos(vector<int>&in , vector<int>&pos,int &n,int &ele){
        for(int i =0 ; i<n ;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
      TreeNode*solve(vector<int>& in, vector<int>& pos, int &ind , int  ins , int ined , int &n){
          if(ins>ined|| ind<0){
              return NULL;
          }
          int ele = pos[ind];
          ind--;
          TreeNode* temp = new TreeNode(ele);
          int  posi =findpos(in, pos , n , ele);
          temp->right = solve(in, pos,ind , posi+1 , ined ,n);
          temp->left = solve(in, pos,ind , ins , posi-1 ,n);
          
          return temp;
      }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int n = in.size();
        int ind = n-1;
        TreeNode* ans = solve(in , pos, ind , 0, n-1 , n);
        return ans;
    }
};