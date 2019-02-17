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
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        else
        {
            vector<int> subtree_height;
            for(const auto& each_subtree : root->children)
            {
                subtree_height.push_back(maxDepth(each_subtree));
            }
            if(subtree_height.empty())
                return 1;
            else
                return 1 + (*max_element(subtree_height.begin(), subtree_height.end()));
        }
    }
    
};
