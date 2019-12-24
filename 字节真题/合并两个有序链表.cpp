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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode(-1);
        ListNode* it = new_head;
        ListNode* newhead1 = new ListNode(-1);
        newhead1->next = l1;
        ListNode* newhead2 = new ListNode(-1);
        newhead2->next = l2;
        auto it1 = newhead1;
        auto it2 = newhead2;
        while(it1->next != nullptr && it2->next != nullptr)
        {
            ListNode* split_node = nullptr;
            if(it1->next->val < it2->next->val)
            {
                split_node = it1->next;
                it1->next = split_node->next;
                it->next = split_node;
                it = it->next;
            }
            else if(it1->next->val > it2->next->val)
            {
                split_node = it2->next;
                it2->next = split_node->next;
                it->next = split_node;
                it = it->next;
            }
            else
            {
                split_node = it1->next;
                it1->next = split_node->next;
                it->next = split_node;
                it = it->next;
                split_node = it2->next;
                it2->next = split_node->next;
                it->next = split_node;
                it = it->next;
            }
        }
        while(it1->next != nullptr)
        {
            ListNode* split_node = it1->next;
            it1->next = split_node->next;
            it->next = split_node;
            it = it->next;
        }
        while(it2->next != nullptr)
        {
            ListNode* split_node = it2->next;
            it2->next = split_node->next;
            it->next = split_node;
            it = it->next;
        }
        it->next = nullptr;
        ListNode* t = new_head;
        new_head = new_head->next;
        delete t;
        return new_head;
    }
};
