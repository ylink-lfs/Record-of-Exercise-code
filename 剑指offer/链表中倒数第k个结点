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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        auto it = pListHead;
        int step = 0;
        while(it && step < k)
        {
            it = it->next;
            step++;
        }
        
        if(step < k)
        {
            return nullptr;
        }
        auto it2 = pListHead;
        while(it)
        {
            it = it->next;
            it2 = it2->next;
        }
        return it2;
    }
};
