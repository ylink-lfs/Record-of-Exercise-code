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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
        {
            return nullptr;
        }
        vector<TreeNode*> v;
        getSeq(pRoot, v);
        if(v.size() < k)
            return nullptr;
        return v[k - 1];
    }

    void getSeq(TreeNode* root, vector<TreeNode*>& v)
    {
        if(root != nullptr)
        {
            getSeq(root->left, v);
            v.push_back(root);
            getSeq(root->right, v);
            
        }
    }
};
