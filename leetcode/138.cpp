//I didn't notice the random pointer may form a circulate link, which causes runtime error. Use a set in global range
//to prevent infinity recursion.
//notice: As long as "random" appear in the problem, be very careful with recursion ending condition

set<RandomListNode*> mp;
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(!head)     
        {
            return nullptr;
        }
        else if (mp.find(head) != mp.end())
        {
            RandomListNode* root = new RandomListNode(head->label);
            root->next = head->next;
            root->random = head->random;
            return root;
        }
        else
        {            
            mp.insert(head);
            RandomListNode* root = new RandomListNode(head->label);
            root->next = copyRandomList(head->next);
            root->random = copyRandomList(head->random);
            return root;            

        }
    }
};
