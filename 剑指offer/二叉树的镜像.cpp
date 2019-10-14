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
    void Mirror(TreeNode *proot) {
        if(proot)
        {
            swap(proot->left, proot->right);
            Mirror(proot->left);
            Mirror(proot->right);
        }
    }
};
