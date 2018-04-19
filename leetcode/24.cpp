class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummynode = new ListNode(0);
        ListNode* temp;
        dummynode->next = head;
        ListNode *pre, *cur1, *cur2;
        if(head == nullptr || head->next == nullptr)
            return head;
        pre = dummynode;
        cur1 = head;
        cur2 = head->next;
        do
        {
            cur1->next = cur2->next;
            cur2->next = cur1;
            pre->next = cur2;
            temp = cur2;
            cur2 = cur1;
            cur1 = temp;
            cur2 = cur2->next;
            if(!cur2)
                break;
            cur2 = cur2->next;
            cur1 = cur1->next->next;
            pre = pre->next->next;
        } while(cur2);
        return dummynode->next;
    }
};
