//searched for hints
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        else
        {
            
            root->right = convertBST(root->right);
            
            if(add_once)
            {
                summy += root->val;
                root->val = summy;
            }
            else
            {
                add_once = true;
                summy += root->val;
            }
            
            root->left = convertBST(root->left);            
            
            return root;
        }
        
    }
    int summy = 0;
    bool add_once = false;
};
