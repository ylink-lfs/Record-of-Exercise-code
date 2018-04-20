class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right != nullptr)
            return sumOfLeftLeaves(root->right);
        else if (root->left == nullptr && root->right == nullptr)
            return 0;
        else if (root->left->left == nullptr && root->left->right == nullptr)
        {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        else
        {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);            
        }
    }
};
