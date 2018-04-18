class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int connected_counter = 0;
        ListNode* current = head;
        bool first_found = false;
        while(current)
        {
            if(find(G.begin(), G.end(), current->val) == G.end())
            {
                first_found = false;
            }
            else
            {
                if(!first_found)
                {
                    first_found = true;
                    connected_counter++;
                }
            }
            current = current->next;
        }
        return connected_counter;
    }
};
