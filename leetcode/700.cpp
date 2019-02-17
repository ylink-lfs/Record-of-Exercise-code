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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        else if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        else if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return root;
        }
    }
};
