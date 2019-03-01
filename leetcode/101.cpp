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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        else if (!l || !r)
            return false;
        else
            return (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
};
