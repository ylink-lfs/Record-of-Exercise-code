class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)  //0, 1, 2 elems
            return head;
        ListNode* pnew = nullptr;
        ListNode* current = head->next->next;
        ListNode* pre = head->next;
        ListNode* insertion_point = head;
        ListNode* temp = nullptr;
        while(current)
        {
            pnew = new ListNode(current->val);
            pnew->next = insertion_point->next;
            insertion_point->next = pnew;
            insertion_point = insertion_point->next;
            temp = current;
            current = current->next;
            pre->next = current;
            delete temp;
            if(!current)
                break;
            else
            {
                current = current->next;
                pre = pre->next;
            }
        }
        return head;
    }
};
