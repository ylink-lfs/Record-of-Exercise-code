/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* phead) {
        if(!phead || phead->next == nullptr)
        {
            return phead;
        }
        ListNode* pre = nullptr;
        auto mid = phead;
        auto after = phead->next;
        while(after)
        {
            mid->next = pre;
            pre = mid;
            mid = after;
            after = after->next;
        }
        mid->next = pre;
        return mid;
    }
};
