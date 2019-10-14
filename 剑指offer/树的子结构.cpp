/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr || t2 == nullptr)
        {
            return false;
        }
        else if(t1->val == t2->val)
        {
            bool res = check_equ(t1, t2);
            if(res)
            {
                return true;
            }
        }
        return HasSubtree(t1->left, t2) || HasSubtree(t1->right, t2);
    }
    
    bool check_equ(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        else if(t1 == nullptr || t2 == nullptr)
        {
            return false;
        }
        else if(t1->val != t2->val)
        {
            return false;
        }
        else
        {
            return true &&
                (t2->left ? check_equ(t1->left, t2->left) : true) &&
                (t2->right ? check_equ(t1->right, t2->right) : true);
        }
    }
};
