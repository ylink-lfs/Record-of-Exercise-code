ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
            return nullptr;
        ListNode* dummynode = new ListNode(INT_MIN);
        dummynode->next = head;
        ListNode* pos = head;
        while(pos && pos->val < x)
            pos = pos->next;
        if(!pos)
            return head;
        ListNode* current = pos;
        ListNode* temp = nullptr;
        ListNode* pnew = nullptr;
        do
        {
            while(current && current->val >= x)
                current = current->next;
            if(!current)
                break;
            pnew = new ListNode(current->val);
            temp = findPrevious(dummynode, pos);
            pnew->next = pos;
            temp->next = pnew;
            temp = findPrevious(dummynode, current);
            temp->next = current->next;
            current = pos;
        }while(current);
        return dummynode->next;
    }
    ListNode* findPrevious(ListNode* head, ListNode* node)
    {
        ListNode* current = head;
        while(current->next != node)
        {
            current = current->next;
        }
        return current;
    }
