class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        ListNode* new_list = new ListNode(INT_MIN);
        ListNode* new_c = new_list;
        ListNode* current = head;
        ListNode* temp = nullptr;
        while(current)
        {
            if(current->val != val)
            {
                temp = current;
                current = current->next;
                new_c->next = temp;
                new_c = new_c->next;
                new_c->next = NULL;
            }
            else
            {
                current = current->next;
            }
        }
        return new_list->next;
    }
};
