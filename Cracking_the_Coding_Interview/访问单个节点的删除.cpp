/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if(pNode == nullptr || pNode->next == nullptr)
            return false;
        auto nextContent = pNode->next->val;
        pNode->val = nextContent;
        auto t = pNode->next;
        pNode->next = t->next;
        delete t;
        return true;
    }
};
