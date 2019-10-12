/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        if(!p1 || !p2)
        {
            return p1 ? p1 : p2;
        }
        else
        {
            auto res = new ListNode(0x7fffffff);
            auto h1 = p1;
            auto h2 = p2;
            auto it1 = h1;
            auto it2 = h2;
            auto it_res = res;
            while(it1 && it2)
            {
                if(it1->val < it2->val)
                {
                    auto temp = new ListNode(it1->val);
                    it1 = it1->next;
                    it_res->next = temp;
                    it_res = it_res->next;
                }
                else if(it1->val > it2->val)
                {
                    auto temp = new ListNode(it2->val);
                    it2 = it2->next;
                    it_res->next = temp;
                    it_res = it_res->next;
                }
                else
                {
                    auto temp = new ListNode(it1->val);
                    it1 = it1->next;
                    it_res->next = temp;
                    it_res = it_res->next;
                    temp = new ListNode(it2->val);
                    it2 = it2->next;
                    it_res->next = temp;
                    it_res = it_res->next;
                }
            }
            it_res->next = it1 ? it1 : it2;
            auto t = res;
            res = res->next;
            delete t;
            return res;
        }
    }
};
