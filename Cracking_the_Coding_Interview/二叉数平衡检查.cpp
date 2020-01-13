/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    bool isBalance(TreeNode* root)
    {
        int dummy;
        return isBalance(root, dummy);
    }
    
    bool isBalance(TreeNode* root, int& height)
    {
        if(root == nullptr)
        {
            height = 0;
            return true;
        }
        int lheight, rheight;
        bool balanced = false;
        if(isBalance(root->left, lheight) && isBalance(root->right, rheight))
        {
            int diff = lheight - rheight;
            if(diff <= 1 && diff >= -1)
            {
                balanced = true;
            }
            else
            {
                balanced = false;
            }
        }
        height = max(lheight, rheight) + 1;
        return balanced;
    }
};
