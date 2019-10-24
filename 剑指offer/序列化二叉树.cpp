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
    char* Serialize(TreeNode *root) 
    {
        string res;
        recur_serialize(res, root);
        char* t = new char[res.size() + 5];
        strcpy(t, res.c_str());
        return t;
    }
    
    void recur_serialize(string& s, TreeNode* root)
    {
        if(root == nullptr)
        {
            s.push_back('#');
        }
        else
        {
            s.insert(s.size(), to_string(root->val));
            s.push_back('!');
            recur_serialize(s, root->left);
            recur_serialize(s, root->right);
        }
    }
    
    TreeNode* Deserialize(const string& str) 
    {
        auto it = str.cbegin();
        return recur_deserialize(it, str);
    }
    
    TreeNode* recur_deserialize(string::const_iterator& it, const string& str)
    {
        int n;
        TreeNode* root = nullptr;
        if(read_str(n, it, str))
        {
            root = new TreeNode(n);
            root->left = recur_deserialize(it, str);
            root->right = recur_deserialize(it, str);
        }
        return root;
    }
    
    bool read_str(int& n, string::const_iterator& it, const string& str)
    {
        if(*it == '#')
        {
            it++;
            return false;
        }
        else
        {
            auto end_it = it;
            while(*end_it != '#' && *end_it != '!')
                end_it++;
            n = stoi(string(it, end_it));
            if(*end_it == '#')
                it = end_it;
            else
                it = end_it + 1;
            return true;
        }
    }
};
