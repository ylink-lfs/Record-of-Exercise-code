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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> seq;
        getValSequence(root, seq);
        TreeNode* new_tree = new TreeNode(seq[0]);
        TreeNode* it = new_tree;
        for(int i = 1; i < seq.size(); i++)
        {
            TreeNode* tmp = new TreeNode(seq[i]);
            it->right = tmp;
            it = tmp;
        }
        return new_tree;
    }
    void getValSequence(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        getValSequence(root->left, v);
        v.push_back(root->val);
        getValSequence(root->right, v);
    }
};
