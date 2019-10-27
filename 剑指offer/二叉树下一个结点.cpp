/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* res = nullptr;
        if(pNode == nullptr)
            return nullptr;
        else if(pNode->right)
        {
            res = pNode->right;
            while(res->left)
            {
                res = res->left;
            }
            return res;
        }
        else if(!pNode->next)
        {
            return nullptr;
        }
        else if(pNode->next->left == pNode)
        {
            return pNode->next;
        }
        else
        {
            res = pNode;
            while(res->next && res->next->right == res)
            {
                res = res->next;
            }
            if(res->next)
                res = res->next;
            else
                res = nullptr;
            return res;
        }
    }
};
