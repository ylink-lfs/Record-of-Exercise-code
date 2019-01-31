class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode* reverse(ListNode* l) {
        if (!l || !(l->next))
		return l;
	ListNode* pre = l;
	ListNode* cur = l->next;
	ListNode* after = l->next->next;
	while (after)
	{
		cur->next = pre;
		pre = cur;
		cur = after;
		after = after->next;
	}
	cur->next = pre;
	l->next = nullptr;
	return cur;
    }
};
