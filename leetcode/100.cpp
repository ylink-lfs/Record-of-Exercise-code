class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        else if ((p && !q) || (!p && q))
            return false;
        else
        {
            if(p->val == q->val)
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            else
            {
                return false;
            }
        }
    }
};
