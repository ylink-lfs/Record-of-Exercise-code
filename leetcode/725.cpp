class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) 
    {
        int length = getLength(root);
        vector<int> split_plan(k);
        if(k >= length)
        {            
            fill(split_plan.begin(), split_plan.end(), 0);
            fill(split_plan.begin(), split_plan.begin() + length, 1);
        }
        else
        {
            fill(split_plan.begin(), split_plan.end(), 0);
            auto it = split_plan.begin();
            while(sum_up(split_plan) < length)
            {
                (*it)++;
                it++;
                if(it == split_plan.end())
                    it = split_plan.begin();
            }
        }
        vector<ListNode*> address_container;
        ListNode* head_address = root;
        ListNode* current = root;
        ListNode* temp = nullptr;
        int split_counter;
        auto it = split_plan.begin();
        while(it != split_plan.end())
        {
            split_counter = *it;
            for(int i = 0; i < split_counter - 1; i++)
            {
                if(current != nullptr)
                     current = current->next;
            }
            temp = current;
            if(temp != nullptr)
                current = current->next;
            else
                current = nullptr;
            address_container.push_back(head_address);
            if(temp != nullptr)
                temp->next = nullptr;
            head_address = current;
            it++;
        }
        return address_container;    
        
    }   
    int getLength(ListNode* head)
    {
        ListNode* current = head;
        if(!current)
            return 0;
        else
        {
            int counter = 0;
            while(current)
            {
                current = current->next;
                counter++;
            }
            return counter;
        }
    }
    int sum_up(vector<int> vec)
    {
        int sum = 0;
        for(auto num : vec)
            sum += num;
        return sum;
    }
};
