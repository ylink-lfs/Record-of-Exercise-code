class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        unordered_set<ListNode*> address;
        ListNode* current = head;
        do
        {
            if(address.find(current) != address.end())
            {
                return current;
            }
            address.insert(current);
            current = current->next;
        } while(current);
        return NULL;
    }
};
