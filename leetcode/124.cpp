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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        f(root, res);
        return res;
    }
    
    int f(TreeNode* root, int& val)
    {
        if(!root)
        {
            return 0;
        }
        else
        {
            int left_val = max(0, f(root->left, val));
            int right_val = max(0, f(root->right, val));
            val = max(val, left_val + right_val + root->val);
            return root->val + max(left_val, right_val);
        }
    }
};
