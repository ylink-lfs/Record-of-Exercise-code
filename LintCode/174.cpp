class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) 
    {
        int len=0;
        int i=1;
        ListNode* current;
        ListNode* pre;
        current=head;
        while(current!=NULL)
        {
            len++;
            current=current->next;
        }
        //len:actural length
        current=head;
        len=len-n+1;
        while(i<len)
        {
            if(current==head)
            {
                current=current->next;
                i++;
                continue;
            }
            else
            {
                pre=current;
                current=current->next;
                i++;
                continue;
            }
        }
        
        if(current==head)
        {
            head=head->next;
        }
        else
        {
            (pre->next)=(current->next);
        }
        return head;
    }
};
