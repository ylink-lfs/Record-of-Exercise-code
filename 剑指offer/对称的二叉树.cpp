/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* proot)
    {
        if(!proot)
        {
            return true;
        }
        TreeNode* mirror = make_mirror(proot);
        return check_mirror(proot, mirror);
    }
    
    TreeNode* make_mirror(TreeNode* root)
    {
        if(root)
        {
            swap(root->left, root->right);
            make_mirror(root->left);
            make_mirror(root->right);
        }
        return root;
    }
    
    bool check_mirror(TreeNode* t1, TreeNode* t2)
    {
        if(!t1 && !t2)
            return true;
        else if(!t1 || !t2)
            return false;
        else if(t1->val != t2->val)
            return false;
        else
            return check_mirror(t1->left, t2->right) && check_mirror(t1->right, t2->left);
            
    }

};
