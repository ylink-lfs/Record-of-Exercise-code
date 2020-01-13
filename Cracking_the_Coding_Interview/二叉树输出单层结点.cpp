/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root == nullptr || dep == 0)
            return nullptr;
        else if(root->left == nullptr && root->right == nullptr && dep == 1)
            return new ListNode(root->val);
        else
        {
            ListNode* res = new ListNode(-1);
            ListNode* it = res;
            queue<pair<TreeNode*, int>> q;
            q.push(make_pair(root, 1));
            while(!q.empty())
            {
                TreeNode* cur_node = q.front().first;
                int cur_dep = q.front().second;
                q.pop();
                if(cur_dep == dep)
                {
                    ListNode* t = new ListNode(cur_node->val);
                    it->next = t;
                    it = it->next;
                }
                else if(cur_dep > dep)
                    break;
                if(cur_node->left)
                {
                    q.push(make_pair(cur_node->left, cur_dep + 1));
                }
                if(cur_node->right)
                {
                    q.push(make_pair(cur_node->right, cur_dep + 1));
                }
            }
            it = res;
            res = res->next;
            delete it;
            return res;
        }
    }
};
