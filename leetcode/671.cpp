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
    set<int> s;
    int findSecondMinimumValue(TreeNode* root) {
        findInDepth(root, 1);
        if(s.size() <= 1)
            return -1;
        else
        {
            auto it = s.begin();
            it++;
            return *it;
            
        }
    }
    void findInDepth(TreeNode* root, int current_depth)
    {
        if(!root)
            return;
        else
        {
            s.insert(root->val);
            findInDepth(root->left, current_depth + 1);
            findInDepth(root->right, current_depth + 1);
        }
    }
};
