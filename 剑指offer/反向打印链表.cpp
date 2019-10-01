/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        recur_print(res, head);
        return res;
    }
    
    void recur_print(vector<int>& v, ListNode* head)
    {
        if(head == nullptr)
        {
            return;
        }
        else
        {
            recur_print(v, head->next);
            v.push_back(head->val);
        }
    }
};
