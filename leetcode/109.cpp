class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == nullptr)
            return nullptr;
        vector<int> elem;
        ListNode* current = head;
        while(current)
        {
            elem.push_back(current->val);
            current = current->next;
        }
        int c_index = 0;
        TreeNode* target_tree = nullptr;

        while(c_index < elem.size())
        {
            target_tree = insertion(target_tree, elem[c_index]);
            c_index++;          
        }
        
        return target_tree;
    }
    
    TreeNode* insertion(TreeNode* root, int elem)
    {

        if(!root)
        {
            root = new TreeNode(elem);
        }
        else if(root->val < elem)
        {
            root->right = insertion(root->right, elem);
            if(abs(get_height(root->right) - get_height(root->left)) == 2)
            {
                if(elem > root->right->val)
                {
                    root = LL_Rotation(root);
                }
                else
                {
                    root = RL_Rotation(root);
                }
            }
        }
        else if (root->val > elem)
        {
            root->left = insertion(root->left, elem);
            if(abs(get_height(root->right) - get_height(root->left)) == 2)
            {
                if(elem < root->left->val)
                {
                    root = RR_Rotation(root);
                }
                else
                {
                    root = LR_Rotation(root);
                }
            }
        }
        else
        {
            ;  //element already exist, do nothing
        }
        return root;
    }
    
    TreeNode* LL_Rotation(TreeNode* root)
    {
        TreeNode* p1 = root;
        TreeNode* p2 = root->right;
        TreeNode* t = p2->left;
        p1->right = t;
        p2->left = p1;
        return p2;
    }
    TreeNode* RL_Rotation(TreeNode* root)
    {
        root->right = RR_Rotation(root->right);
        return LL_Rotation(root);
    }
    TreeNode* RR_Rotation(TreeNode* root)
    {
        TreeNode* p1 = root;
        TreeNode* p2 = root->left;
        TreeNode* t = p2->right;
        p1->left = t;
        p2->right = p1;
        return p2;
    }
    TreeNode* LR_Rotation(TreeNode* root)
    {
        root->left = LL_Rotation(root->left);
        return RR_Rotation(root);
    }
    int get_height(TreeNode* root)
    {
        if(root == nullptr)
            return -1;
        else
        {
            return max(get_height(root->left), get_height(root->right)) + 1;
        }
    }
    
};

//still not familiar with AVL tree, require more practice
