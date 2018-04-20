class Solution {
public:
    string tree2str(TreeNode* t) {
        string str;
        if(!t)
            return str;
        str += to_string(t->val);
        if(t->left && t->right)
        {
            return str + '(' + tree2str(t->left) + ')' + '(' + tree2str(t->right) + ')';
        }
        else if (t->left && !(t->right))
        {
            return str + '(' + tree2str(t->left) + ')';
        }
        else if (!(t->left) && t->right)
        {
            return str + "()" + '(' + tree2str(t->right) + ')';
        }
        else
        {
            return str;
        }
    }
};
