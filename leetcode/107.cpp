//Careful with vector resizing. Forgetting this step may cause exception.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> level_count;
        vector<vector<int>>res;
        queue<TreeNode*> q;
        stack<TreeNode*> route;
        TreeNode* current = nullptr;
        if(root == nullptr)
            return res;
        q.push(root);
        while(!q.empty())
        {
            level_count.push_back(q.size());
            for(int i = 0; i < level_count[level_count.size() - 1]; i++)
            {
                current = q.front();
                q.pop();
                route.push(current);
                if(current->right)
                    q.push(current->right);
                if(current->left)
                    q.push(current->left);
            }
        }
        res.resize(level_count.size());
        for(int i = level_count.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < level_count[i]; j++)
            {
                current = route.top();
                route.pop();
                res[level_count.size() - 1 - i].push_back(current->val);
            }
        }
        return res;
    }
};
