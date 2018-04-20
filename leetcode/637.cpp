//Checked others' solution. Not familiar enough with levelorder traversal. q.size() represents node count of each level. Stucked here.
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if(root == nullptr)
            return res;
        else
        {
            q.push(root);
        }
        TreeNode* current = nullptr;
        int node_count;
        double node_sum;
        while(!q.empty())
        {
            node_count = q.size();
            node_sum = 0;
            for(int i = 0; i < node_count; i++)
            {
                current = q.front();
                q.pop();
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);                
                node_sum += current->val;
            }
            res.push_back(node_sum / node_count);
        }
        return res;
    }

};
