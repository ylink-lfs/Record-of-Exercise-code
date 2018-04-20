class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        else
        {
            int cache = height(root->left) + height(root->right);
            if(max_d < cache)
                max_d = cache;
            int t1 = diameterOfBinaryTree(root->left);
            int t2 = diameterOfBinaryTree(root->right);
            cache = t1 < t2 ? t2 : t1;
            max_d = max_d > cache ? max_d : cache;
            return max_d;
        }
    }
    int height(TreeNode* root){
        if(!root)
            return 0;
        else
            return max(height(root->left), height(root->right)) + 1;
    }
    int max_d = 0;
};
