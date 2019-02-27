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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lower = p->val < q->val ? p : q;
        TreeNode* upper = lower == p ? q : p;
        if(root->val > lower->val && root->val < upper->val)
        {
            return root;
        }
        else if (root->val == lower->val)
            return lower;
        else if (root->val == upper->val)
            return upper;
        else if (root->val > upper->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
