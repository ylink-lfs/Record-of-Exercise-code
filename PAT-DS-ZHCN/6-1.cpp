List Reverse(List L)
{
    if(L == NULL || L->Next == NULL)
        return L;
    else if(L->Next->Next == NULL)
    {
        PtrToNode newhead = L->Next;
        L->Next = NULL;
        newhead->Next = L;
        return newhead;
    }
    
    else
    {
        PtrToNode pre = L;
        PtrToNode cur = L->Next;
        PtrToNode nextnode = L->Next->Next;
        pre->Next = NULL;
        
        while(nextnode)
        {
            PtrToNode tmpptr = nextnode->Next;
            cur->Next = pre;
            nextnode->Next = cur;
            pre = cur;
            cur = nextnode;
            nextnode = tmpptr;
        }
        return cur;
    }
    
}
