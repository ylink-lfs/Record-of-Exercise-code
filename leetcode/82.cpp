class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        vector<int> vec;
        unordered_map<int, int> mp;
        ListNode* current = head;
        while(current)
        {
            vec.push_back(current->val);
            if(mp.find(current->val) != mp.end())
            {
                mp[current->val]++;
            }
            else
            {
                mp[current->val] = 1;
            }
            current = current->next;
        }
        ListNode* dummynode = new ListNode(INT_MIN);
        ListNode* pnew = nullptr;
        current = dummynode;
        auto it = vec.begin();
        while(it != vec.end())
        {
            if(mp[*it] > 1)
            {
                it += mp[*it];
                continue;
            }
            else
            {
                pnew = new ListNode(*it);
                current->next = pnew;
                current = current->next;
                it++;
            }
        }
        return dummynode->next;
    }
};
