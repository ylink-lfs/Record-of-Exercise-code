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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2)
            return nullptr;
        set<ListNode*> st;
        while(pHead1)
        {
            st.insert(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2)
        {
            if(st.find(pHead2) != st.end())
            {
                return pHead2;
            }
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};
