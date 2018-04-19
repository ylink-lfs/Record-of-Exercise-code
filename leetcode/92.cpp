//Defensive solution. In-place reverse can be done
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(!head || n - m == 0)
            return head;
        ListNode* dummynode = new ListNode(INT_MIN);
        dummynode->next = head;

        ListNode* pos1;
        ListNode* pos2;
        ListNode* subhead;
        ListNode* receive;
        ListNode* current = dummynode;
        int counter = 0;
        while(counter < m)
        {
            if(counter + 1 == m)
            {
                pos1 = current;
            }
            current = current->next;
            counter++;
        }
        subhead = current;
        while(counter < n)
        {
            current = current->next;
            counter++;
        }
        if(current)
            pos2 = current->next;
        else
            pos2 = nullptr;
        if(current)
            current->next = nullptr;
        pos1->next = nullptr;
        subhead = reverse(subhead);
        pos1->next = subhead;
        current = subhead;
        while(current->next)
            current = current->next;
        current->next = pos2;
        return dummynode->next;
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head || head->next == nullptr)
            return head;
        else if (head->next->next == nullptr)
        {
            ListNode* cur1 = head;
            ListNode* cur2 = head->next;
            cur2->next = cur1;
            cur1->next = nullptr;
            return cur2;
        }
        else
        {
            ListNode* pre = nullptr;
            ListNode* now = head;
            ListNode* after = head->next;
            while(after)
            {
                now->next = pre;

                if(after)             
                {
                    pre = now;                    
                    now = after;
                    after = after->next;
                }
            }
            now->next = pre;
            return now;
        }
    }
};
