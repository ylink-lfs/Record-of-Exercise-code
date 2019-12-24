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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* it1 = headA;
        while(it1 != nullptr)
        {
            len1++;
            it1 = it1->next;
        }
        ListNode* it2 = headB;
        while(it2 != nullptr)
        {
            len2++;
            it2 = it2->next;
        }
        int diff = abs(len1 - len2);
        if(len1 > len2)
        {
            it1 = headA;
            it2 = headB;
        }
        else
        {
            it1 = headB;
            it2 = headA;
        }
        for(int i = 0; i < diff; i++)
        {
            it1 = it1->next;
        }
        while(it1 && it2 && it1 != it2)
        {
            it1 = it1->next;
            it2 = it2->next;
        }
        return it1;
        
     }
};
