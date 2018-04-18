class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* new_list = new ListNode(0);
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* pnew = nullptr;
        ListNode* new_c = new_list;
        if(c1 == nullptr && c2 == nullptr)
            return new_list->next;
        while(c1 != nullptr && c2 != nullptr)
        {
            if(c1->val < c2->val)
            {
                pnew = new ListNode(c1->val);
                new_c->next = pnew;
                new_c = new_c->next;
                c1 = c1->next;
            }
            else if (c1->val > c2->val)
            {
                pnew = new ListNode(c2->val);
                new_c->next = pnew;
                new_c = new_c->next;
                c2 = c2->next;
            }
            else
            {
                pnew = new ListNode(c1->val);
                new_c->next = pnew;
                new_c = new_c->next;
                pnew = new ListNode(c1->val);
                new_c->next = pnew;
                new_c = new_c->next;
                c1 = c1->next;
                c2 = c2->next;
            }
        }
        new_c->next = c1 ? c1 : c2;
        return new_list->next;     
    }
};
