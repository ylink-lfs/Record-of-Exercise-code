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
    bool isCousins(TreeNode* root, int x, int y) {
        auto father_x = findFather(root, x, 0);
        auto father_y = findFather(root, y, 0);
        if(root->val == x)
            father_x.second = -1;
        if(root->val == y)
            father_y.second = -1;
        return (father_x.first != father_y.first) && (father_x.second == father_y.second);
    }
    pair<TreeNode*, int> findFather(TreeNode* root, int x, int depth)
    {
        if(!root)
            return make_pair(nullptr, depth);
        else if ((root->left && root->left->val == x) || (root->right && root->right->val == x))
            return make_pair(root, depth);
        else
        {
            auto lft_res = findFather(root->left, x, depth + 1);
            return lft_res.first == nullptr ? findFather(root->right, x, depth + 1) : lft_res;
        }
    }

};
