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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if((l1->val == 0 && l1->next == nullptr) || (l2->val == 0 && l2->next == nullptr))
            return l1->val == 0 ? l2 : l1;
        else
        {
            ListNode* it1 = l1;
            ListNode* it2 = l2;
            vector<ListNode*> node_tobe_delete;
            while(it1 != nullptr && it2 != nullptr)
            {
                if(it1->next == nullptr && it2->next != nullptr)
                {
                    ListNode* zero_node = new ListNode(0);
                    node_tobe_delete.push_back(zero_node);
                    it1->next = zero_node;
                }
                else if(it1->next != nullptr && it2->next == nullptr)
                {
                    ListNode* zero_node = new ListNode(0);
                    node_tobe_delete.push_back(zero_node);
                    it2->next = zero_node;
                }
                it1 = it1->next;
                it2 = it2->next;
            }
            it1 = l1; it2 = l2;
            ListNode* res = new ListNode(-1);
            ListNode* it = res;
            int carry = 0;
            while(it1 != nullptr && it2 != nullptr)
            {
                int add_num = it1->val + it2->val + carry;
                ListNode* new_node = new ListNode(add_num % 10);
                it->next = new_node;
                it = it->next;
                carry = add_num / 10;
                it1 = it1->next;
                it2 = it2->next;
            }
            if(carry != 0)
                it->next = new ListNode(carry);
            it = res;
            res = res->next;
            delete it;
            for(auto e : node_tobe_delete)
                delete e;
            return res;
        }
    }
};
