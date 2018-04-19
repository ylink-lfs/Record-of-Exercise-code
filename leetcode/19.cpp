class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* dummynode = new ListNode(INT_MIN);
        dummynode->next = head;
        ListNode* current = head;
        int length_count = 0;
        while(current)
        {
            current = current->next;
            length_count++;
        }
        ListNode* pre = dummynode;
        current = head;
        int position = length_count - n;
        for(int i = 0; i < position; i++)
        {
            current = current->next;
            pre = pre->next;
        }
        pre->next = current->next;
        head = dummynode->next;
        return head;
    }
};
