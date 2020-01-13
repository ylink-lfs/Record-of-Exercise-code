/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        set<UndirectedGraphNode*> reached_nodes;
        bool check_reach = false;
        dfs(a, reached_nodes, check_reach, b);
        if(!check_reach)
        {
            reached_nodes.clear();
            dfs(b, reached_nodes, check_reach, a);
        }
        return check_reach;
    }
    
    void dfs(UndirectedGraphNode* cur_node, set<UndirectedGraphNode*>& reached_nodes, bool& reachdest, UndirectedGraphNode* expected_dest)
    {
        if(cur_node == expected_dest)
        {
            reachdest = true;
        }
        else if(reached_nodes.find(cur_node) != reached_nodes.end())
        {}
        else
        {
            reached_nodes.insert(cur_node);
            for(auto e : cur_node->neighbors)
            {
                dfs(e, reached_nodes, reachdest, expected_dest);
            }
        }
    }
};
