/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* first = head;
        ListNode* mid = first->next;
        ListNode* last = mid->next;
        while(last != nullptr)
        {
            mid->next = first;
            first = mid;
            mid = last;
            last = last->next;
        }
        mid->next = first;
        head->next = nullptr;
        return mid;
    }
};
