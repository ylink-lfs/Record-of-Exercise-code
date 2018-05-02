class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) 
    {
        ListNode* current=head;
        ListNode* pre;
        int check;
        while(current!=NULL)
        {
            check=current->val;
            if(check==val)
            {
                if(current==head)
                {
                    head=head->next;
                    current=head;
                    continue;
                }
                
                else
                {
                    (pre->next)=(current->next);
                    current=current->next;
                    continue;
                }
            }
            
            pre=current;
            current=current->next;
            
        }
        
        return head;
    }
};
