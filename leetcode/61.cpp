class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* current = head;
        int length = 1;
        while(current->next)      
        {
            current = current->next;
            length++;
        }
        current->next = head;
        k %= length;
        int step = length - k - 1;
        for(int i = 0; i < step; i++)
            head = head->next;
        
        ListNode* new_head = head->next;
        head->next = nullptr;
        return new_head;
    }
};
