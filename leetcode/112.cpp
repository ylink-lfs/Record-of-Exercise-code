/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        //The original tree is a null tree
        if(!root)
        {
            return false;
        }
        else
        {
            return hasPathSum(root, 0, sum);
        }
    }
    bool hasPathSum(TreeNode* root, int current_sum, int sum)
    {
        if(!root)
        {
            return false;
        }
        else if (current_sum + root->val == sum && (!root->left && !root->right))
        {
            return true;
        }
        else
        {
            return hasPathSum(root->left, current_sum + root->val, sum) || hasPathSum(root->right, current_sum + root->val, sum);
        }
        
    }
};
