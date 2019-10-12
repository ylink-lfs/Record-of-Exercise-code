/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* phead)
    {
        if(!phead || phead->next == phead)
        {
            return phead;
        }
        else if(phead->next == nullptr)
        {
            return nullptr;
        }
        else
        {
            int steps = 0;
            auto slow = phead;
            auto fast = phead;
            do
            {
                fast = fast->next;
                if(!fast)
                {
                    return nullptr;
                }
                fast = fast->next;
                slow = slow->next;
                steps++;
            } while(fast != slow);
            if(!fast)
            {
                return nullptr;
            }
            int circle_node = 0;
            do
            {
                slow = slow->next;
                circle_node++;
            } while(slow != fast);
            auto it1 = phead;
            auto it2 = phead;
            for(int i = 0; i < circle_node; i++)
            {
                it1 = it1->next;
            }
            while(it1 != it2)
            {
                it1 = it1->next;
                it2 = it2->next;
            }
            return it1;
        }
    }
};
