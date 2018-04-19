class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return nullptr;
        else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            
            //no child; 1 child; two children
            if(root->val < L || root->val > R)
            {
                if(root->left == nullptr && root->right == nullptr)
                {
                    return nullptr;
                }
                else if (root->left != nullptr && root->right != nullptr)
                {
                    if(root->val < L)
                        return root->right;
                    else
                        return root->left;
                }
                else
                {   
                    return root->left ? root->left : root->right;
                }
            }
        }

        
        //never forget this line
        return root;
    }
};
