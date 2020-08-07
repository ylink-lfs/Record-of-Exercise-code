/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        vector<vector<int>> res;
        int last_level = 1;
        vector<int> t;
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if(cur.second != last_level)
            {
                res.push_back(t);
                t.clear();
                last_level++;
            }
            t.push_back(cur.first->val);
            if(cur.first->left)
            {
                q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if(cur.first->right)
            {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }
            
        }
        res.push_back(t);
        return res;
    }
};
