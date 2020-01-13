/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* newHead1 = new ListNode(-1);
        ListNode* it1 = newHead1;
        ListNode* newHead2 = new ListNode(-1);
        ListNode* it2 = newHead2;
        ListNode* it = pHead;
        while(it)
        {
            ListNode* t = it;
            it = it->next;
            t->next = nullptr;
            if(t->val < x)
            {
                it1->next = t;
                it1 = it1->next;
            }
            else
            {
                it2->next = t;
                it2 = it2->next;
            }
        }
        it1->next = newHead2->next;
        ListNode* h = newHead1->next;
        delete newHead1;
        delete newHead2;
        return h;
    }
};
