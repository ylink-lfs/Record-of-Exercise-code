/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    struct node_with_depth
    {
        Node* ptr;
        int depth;
    };
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return vector<vector<int>>();
        queue<node_with_depth> q;
        vector<vector<int>> res;
        q.push({root, 0});
        while(!q.empty())
        {
            node_with_depth current = q.front();
            q.pop();
            for(const auto& each_node : current.ptr->children)
            {
                q.push({each_node, current.depth + 1});
            }
            if(int(res.size() - 1) < current.depth)
                res.push_back(vector<int>());
            res[current.depth].push_back(current.ptr->val);
        }
        return res;
    }
};
