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
    ListNode *detectCycle(ListNode *head) {
        //0, 1, 2 elements, no cycle
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return nullptr;
        }
        else
        {
            ListNode* slow = head;
            ListNode* fast = head;
            int go_cnt = 0;
            do {
                slow = slow->next;
                fast = fast->next;
                if(fast == nullptr)
                    return nullptr;
                fast = fast->next;
                go_cnt++;
            } while(slow != nullptr && fast != nullptr && slow != fast);
            //Single line, no cycle
            if(fast == nullptr)
            {
                return nullptr;
            }
            else
            {
                ListNode* ptr_to_tail = head;
                for(int i = 0; i < go_cnt; i++)
                {
                    ptr_to_tail = ptr_to_tail->next;
                }
                ListNode* it = head;
                while(it != ptr_to_tail)
                {
                    it = it->next;
                    ptr_to_tail = ptr_to_tail->next;
                }
                return it;
            }
        }
    }
};
