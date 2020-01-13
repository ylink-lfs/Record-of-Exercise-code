/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
    bool checkBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        else
        {
            vector<int> v;
            traversal(root, v);
            return is_sorted(v.begin(), v.end());
        }
    }
    
    void traversal(TreeNode* root, vector<int>& v)
    {
        if(root != nullptr)
        {
            traversal(root->left, v);
            v.push_back(root->val);
            traversal(root->right, v);
        }
    }
};
