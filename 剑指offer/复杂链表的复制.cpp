/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* node = nullptr;
        if(pHead != nullptr)
        {
            node = new RandomListNode(pHead->label);
            copied_record.insert(make_pair(pHead, node));
            node->next = Clone(pHead->next);
            if(copied_record.find(pHead->random) == copied_record.end())
            {
                node->random = Clone(pHead->random);
            }
            else
            {
                node->random = copied_record[pHead->random];
            }
        }
        return node;
    }
    unordered_map<RandomListNode*, RandomListNode*> copied_record;
};
