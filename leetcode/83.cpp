class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        ListNode* new_c = new_head;
        ListNode* current = head;
        ListNode* pnew = nullptr;
        if(head == NULL)
        {
            return nullptr;
        }
        else
        {
            while(current)
            {
                pnew = new ListNode(current->val);
                if(new_c != new_head && new_c->val == pnew->val)
                {
                    ;
                }
                else
                {
                    new_c->next = pnew;
                    new_c = new_c->next;
                }
                current = current->next;
            }
            return new_head->next;
        }
    }
};
