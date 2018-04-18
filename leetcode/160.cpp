class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        unordered_set<int> set_on;
        ListNode* current_a = headA;
        while(current_a)
        {
            set_on.insert(current_a->val);
            current_a = current_a->next;
        }
        bool appear = false;
        ListNode* current_b = headB;
        ListNode* new_list = new ListNode(INT_MIN);
        ListNode* pnew = nullptr;
        ListNode* new_c = new_list;
        while(current_b)
        {
            if(set_on.find(current_b->val) != set_on.end())
            {
                if(appear == false)
                    appear = true;
                pnew = new ListNode(current_b->val);
                new_c->next = pnew;
                new_c = new_c->next;
            }
            else
            {
                if(appear == true)
                    break;
            }
            current_b = current_b->next;
        }
        return new_list->next;
    }
};
