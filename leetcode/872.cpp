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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        getLeaveVal(root1, res1);
        getLeaveVal(root2, res2);
        return res1 == res2;
    }
    void getLeaveVal(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        else if(!root->left && !root->right)
            v.push_back(root->val);
        else
        {
            getLeaveVal(root->left, v);
            getLeaveVal(root->right, v);
        }
    }
};
