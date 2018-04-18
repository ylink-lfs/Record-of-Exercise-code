class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head)
            return false;
        if(head->next == nullptr)
            return false;
        else
        {
            do
            {
                slow = slow->next;
                fast = fast->next;
                if(fast == nullptr)
                    return false;
                fast = fast->next;
                if(fast == nullptr)
                    return false;
            }while(slow != fast);
            return true;
        }
    }
};
