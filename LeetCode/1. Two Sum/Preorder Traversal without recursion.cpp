//Partial Function to calculate Preorder Traversal without recursion

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode *root)
{

    vector<int> v;
    if (root == NULL)
        return v;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *cur;

    while (!s.empty())
    {
        cur = s.top();
        s.pop();
        v.push_back(cur->val);

        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
    }

    return v;
}
