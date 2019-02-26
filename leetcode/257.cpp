/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return vector<string>();
        string current_path(to_string(root->val));
        vector<string> pathres;
        binaryTreePaths(root, current_path, pathres);
        return pathres;
    }
    void binaryTreePaths(TreeNode* root, string& current_path, vector<string>& result)
    {
        //Null tree
        if(!root)
        {
            return;
        }
        //Leaf node, the end
        else if (!root->left && !root->right)
        {
            result.push_back(current_path);
        }
        //Not the leaf node
        else
        {
            if(root->left)
            {
                string append_str("->" + to_string(root->left->val));
                current_path.append(append_str);
                binaryTreePaths(root->left, current_path, result);
                for(int i = 0; i < append_str.size(); i++)
                {
                    current_path.pop_back();
                }
            }
            if(root->right)
            {
                string append_str("->" + to_string(root->right->val));
                current_path.append(append_str);
                binaryTreePaths(root->right, current_path, result);
                for(int i = 0; i < append_str.size(); i++)
                {
                    current_path.pop_back();
                }
            }
            
        }
    }
};
