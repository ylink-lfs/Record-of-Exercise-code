/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto e : lists)
        {
            if(e)
                pq.push(e);
        }
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while(!pq.empty())
        {
            auto e = pq.top();
            pq.pop();
            cur->next = e;
            cur = cur->next;
            if(cur->next)
                pq.push(cur->next);    
        }
        cur->next = nullptr;
        cur = res;
        res = res->next;
        delete cur;
        return res;
    }
};
