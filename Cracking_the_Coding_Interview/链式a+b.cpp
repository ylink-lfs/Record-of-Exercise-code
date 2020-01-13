/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if(a == nullptr || b == nullptr)
            return a == nullptr ? b : a;
        if((a->val == 0 && a->next == nullptr) || (b->val == 0 && b->next == nullptr))
            return (a->val == 0 && a->next == nullptr) ? b : a;
        ListNode* res = new ListNode(-1);
        ListNode* it = res;
        ListNode* it1 = a;
        ListNode* it2 = b;
        while(it1->next && it2->next)
        {
            it1 = it1->next; it2 = it2->next;
        }
        while(it1->next || it2->next)
        {
            ListNode* t = new ListNode(0);
            ((it1->next == nullptr) ? it1->next : it2->next) = t;
            it1 = it1->next; it2 = it2->next;
        }
        it1 = a; it2 = b;
        bool carry = false;
        while(it1 && it2)
        {
            int curdigit_sum = it1->val + it2->val;
            if(carry)
                curdigit_sum += 1;
            if(curdigit_sum >= 10)
            {
                carry = true;
            }
            else
                carry = false;
            ListNode* newNode = new ListNode(curdigit_sum % 10);
            it->next = newNode;
            it = it->next; it1 = it1->next; it2 = it2->next;
        }
        if(carry)
            it->next = new ListNode(1);
        it = res;
        res = res->next;
        delete it;
        return res;
    }
};
