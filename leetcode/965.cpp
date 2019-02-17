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
    bool isUnivalTree(TreeNode* root) {
        if(!root->left && !root->right)
        {
            return true;
        }
        else if (!root->left)
        {
            return (root->val == root->right->val) && isUnivalTree(root->right);
        }
        else if (!root->right)
        {
            return (root->val == root->left->val) && isUnivalTree(root->left);
        }
        else
        {
            return (root->val == root->left->val && root->val == root->right->val) && isUnivalTree(root->left) && isUnivalTree(root->right);
        }
    }
};
