/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr)
        {
            fast = fast->next;
            if(fast == nullptr)
            {
                break;
            }
            fast = fast->next;
            if(fast == nullptr)
            {
                break;
            }
            slow = slow->next;
        }
        stack<ListNode*> s;
        while(slow->next != nullptr)
        {
            auto t = slow->next;
            s.push(t);
            slow->next = nullptr;
            slow = t;
        }
        ListNode* cur = head;
        ListNode* store = nullptr;
        while(!s.empty())
        {
            ListNode* rev = s.top();
            s.pop();
            store = cur->next;
            cur->next = rev;
            rev->next = store;
            cur = store;
        }
    }
};
