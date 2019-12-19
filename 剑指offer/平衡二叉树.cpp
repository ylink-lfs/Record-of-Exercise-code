class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int psedu;
        return isbalanced(pRoot, psedu);
    }
    bool isbalanced(TreeNode* root, int& n)
    {
        if(root == nullptr)
        {
            n = 0;
            return true;
        }
        else
        {
            int left, right;
            if(isbalanced(root->left, left) && isbalanced(root->right, right))
            {
                int diff = abs(left - right);
                if(diff <= 1)
                {
                    n = 1 + max(left, right);
                    return true;
                }
            }
            return false;
        }
     }
};
