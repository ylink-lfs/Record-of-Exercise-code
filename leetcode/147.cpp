class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* dummynode = new ListNode(INT_MIN);
        dummynode->next = head;
        ListNode* insert_place = dummynode;
        ListNode* temp = nullptr;
        ListNode* pnew = nullptr;
        ListNode* current = nullptr;
        ListNode* min_node = nullptr;
        do
        {
            current = min_node = insert_place->next;
            while(current)
            {
                if(current->val < min_node->val)
                    min_node = current;
                current = current->next;
            }
            pnew = new ListNode(min_node->val);
            pnew->next = insert_place->next;
            insert_place->next = pnew;

            temp = findPrevious(dummynode->next, min_node);
            temp->next = min_node->next;
            insert_place = insert_place->next;
            
        } while(insert_place->next);advance
        return dummynode->next;
    }
    ListNode* findPrevious(ListNode* head, ListNode* node)
    {
        ListNode* current = head;
        while(current && current->next != node)
        {
            current = current->next;
        }
        return current;
    }
};
