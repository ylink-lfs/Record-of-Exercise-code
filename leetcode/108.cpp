//Standard solution use "half point" or "two pointer" skills
//However, mine is also fine because this solution helped me grasp AVL Tree. I used to be afraid of it, but now I can write it out
//casually thanks to problems' push.
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* root = nullptr;
        for(auto num : nums)
        {
            root = insertion(root, num);
        }
        return root;
    }
    int height(TreeNode* root)
    {
        if(root == nullptr)
            return -1;
        else
            return max(height(root->left), height(root->right))+ 1;
    }
    TreeNode* LL_rotation(TreeNode* root)
    {
        TreeNode* p1 = root;
        TreeNode* p2 = root->right;
        p1->right = p2->left;
        p2->left = p1;
        return p2;
    }
    TreeNode* RR_rotation(TreeNode* root)
    {
        TreeNode* p1 = root;
        TreeNode* p2 = root->left;
        p1->left = p2->right;
        p2->right = p1;
        return p2;
    }
    TreeNode* LR_rotation(TreeNode* root)
    {
        root->left = RR_rotation(root->left);
        return LL_rotation(root);
    }
    TreeNode* RL_rotation(TreeNode* root)
    {
        root->right = LL_rotation(root->right);
        return RR_rotation(root);
    }
    TreeNode* insertion(TreeNode* root, int elem)
    {
        if(!root)
        {
            root = new TreeNode(elem);
            return root;
        }
        else if (root->val > elem)
        {
            root->left = insertion(root->left, elem);
            if(abs(height(root->left) - height(root->right)) == 2)
            {
                if(elem < root->left->val)
                {
                    root = RR_rotation(root);
                }
                else
                {
                    root = LR_rotation(root);
                }
            }
        }
        else if (root->val < elem)
        {
            root->right = insertion(root->right, elem);
            if(abs(height(root->left) - height(root->right)) == 2)
            {
                if(elem < root->right->val)
                {
                    root = RL_rotation(root);
                }
                else
                {
                    root = LL_rotation(root);
                }
            }
        }
        return root;
    }
};
