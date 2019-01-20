int Length( List L )
{
  int len = 0;
  PtrToLNode iter = L;
  while(iter)
  {
    len++;
    iter = iter->Next;
  }
  return len;
}
