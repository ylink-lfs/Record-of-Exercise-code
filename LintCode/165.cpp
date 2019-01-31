/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if(!l1) return l2;
        else if (!l2) return l1;
        else
        {
            ListNode* it1 = l1;
            ListNode* it2 = l2;
            ListNode* res = new ListNode();
            ListNode* res_it = res;
            while(it1 && it2)
            {
                if(it1->val <= it2->val)
                {
                    ListNode* tmp = it1;
                    it1 = it1->next;
                    insert_after(res_it, tmp);
                    res_it = res_it->next;
                }
                else
                {
                    ListNode* tmp = it2;
                    it2 = it2->next;
                    insert_after(res_it, tmp);
                    res_it = res_it->next;
                }
            }
            if(it1) res_it->next = it1;
            if(it2) res_it->next = it2;
            res_it = res;
            res = res->next;
            delete res_it;
            return res;
        }
    }
    void insert_after(ListNode* pre_node, ListNode* insert_node)
    {
        insert_node->next = pre_node->next;
        pre_node->next = insert_node;
    }
};
