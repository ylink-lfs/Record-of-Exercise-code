class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        else if (head->next == nullptr)
            return true;
        else
        {
            ListNode* current = head;
            stack<ListNode*> lstack;
            vector<int> lvec;
            while(current)
            {
                lstack.push(current);
                lvec.push_back(current->val);
                current = current->next;
            }
            for(auto it : lvec)
            {
                current = lstack.top();
                lstack.pop();
                if(it != current->val)
                    return false;
            }
            return true;
        }
    }
};
