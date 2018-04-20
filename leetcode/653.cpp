class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        traversal(record, root);
        bool found = false;
        int i, j;
        for(i = 0; i < record.size() - 1; i++)
        {
            for(j = i + 1; j < record.size(); j++)
            {
                if(record[i] + record[j] == k)
                {
                    found = true;
                    break;
                }
            }
        }
        return found;
    }
    vector<int>record;
    void traversal(vector<int>& record, TreeNode* root)
    {
        if(root == nullptr)
            return;
        else
        {
            record.push_back(root->val);
            traversal(record, root->left);
            traversal(record, root->right);
            return;
        }
    }
};
