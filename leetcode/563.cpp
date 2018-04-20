class Solution {
public:
    int findTilt(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        else
        {
            return findTilt(root->left) + findTilt(root->right) + abs(sum(root->left) - sum(root->right));
        }
    }
    
    int sum(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        else if (root->left != nullptr && root->right != nullptr)
        {
            return sum(root->left) + sum(root->right) + root->val;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        else
        {
            return (root->left ? sum(root->left) : sum(root->right)) + root->val;
        }
    }
};
