class Solution {
public:
    /*
     * @param head: the first node of linked list.
     * @return: An integer
     */
    int countNodes(ListNode * head) {
        int count=0;
        ListNode* current=head;
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
        return count;
    }
};
