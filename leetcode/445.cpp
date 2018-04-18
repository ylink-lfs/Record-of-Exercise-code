class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        ListNode* current = l1;
        while(current)
        {
            s1 += (current->val + 48);
            current = current->next;
        }

        current = l2;
        while(current)
        {
            s2 += (current->val + 48);
            current = current->next;
        }
        string res = add_big(s1.size() > s2.size() ? s1 : s2, s1.size() > s2.size() ? s2 : s1);
        ListNode* res_list = new ListNode(INT_MIN);
        ListNode* pnew = nullptr;
        ListNode* establish = res_list;
        auto it = res.begin();
        while(it != res.end())
        {
            pnew = new ListNode(*it - 48);
            establish->next = pnew;
            establish = establish->next;
            it++;
        }
        return res_list->next;
    }
    string add_big(string& s1, string& s2)  //assume s1 is longer
    {
        char modify[2] = {'0', '\0'};
        while(s1.size() > s2.size())
        {
            s2.insert(0, modify);
        }
        string res;
        int index = s1.size() - 1;
        bool check = false;
        do
        {
            modify[0] = (s1[index] + s2[index] - 96) % 10 + 48;
            if(check)
            {
                modify[0] += 1;
                if(modify[0] > '9')
                    modify[0] = '0';
            }
            res.insert(0, modify);
            if(check)
            {
                if(modify[0] == '0')
                {
                    goto tag;
                }
            }
            
            if(s1[index] + s2[index] - 96 >= 10)
            {
                check = true;
            }
            else
            {
                check = false;
            }
            tag:index--;
        } while(index >= 0);
        if(index < 0 && check)
        {
            modify[0] = '1';
            res.insert(0, modify);
        }
        return res;
        
    }
};
