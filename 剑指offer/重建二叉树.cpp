/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty())
        {
            return nullptr;
        }
        TreeNode* new_root = new TreeNode(*pre.begin());
        auto root_in_vin = find(vin.begin(), vin.end(), *pre.begin());
        int left_tree_size = root_in_vin - vin.begin();
        int right_tree_size = vin.size() - left_tree_size - 1;
        if(left_tree_size)
        {
            new_root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, 
                                                              pre.begin() + 1 + left_tree_size),
                                                  vector<int>(vin.begin(), vin.begin() + left_tree_size));
        }
        if(right_tree_size)
        {
            new_root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + left_tree_size, 
                                                                pre.end()),
                                                   vector<int>(vin.begin() + left_tree_size + 1, vin.end()));
        }
        return new_root;
    }

};
