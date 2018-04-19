//notice that space complixity isn't O(1). Standard answer need to use MergeSort. Here is just for accept recode.
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        multiset<int> v;
        ListNode* current = head;
        while(current)
        {
            v.insert(current->val);
            current = current->next;
        }
        current = head;
        auto it = v.begin();
        while(current)
        {
            current->val = *it;
            it++;
            current = current->next;
        }
        return head;
    }
};
