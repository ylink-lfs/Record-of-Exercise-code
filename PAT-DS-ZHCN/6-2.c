List MakeEmpty()
{
  List plist = malloc(sizeof(struct LNode));
  plist->Last = -1;
  return plist;
}

Position Find( List L, ElementType X )
{
  int resindex = 0;
  for(resindex = 0; resindex <= L->Last; resindex++)
  {
    if(L->Data[resindex] == X)
      break;
    else
      continue;
  }
  return resindex > L->Last ? ERROR : resindex;
}
bool Insert( List L, ElementType X, Position P )
{
  if(L->Last == MAXSIZE - 1)
  {
    printf("FULL");
    return false;
  }
  else if(P < 0 || P > L->Last + 1)
  {
    printf("ILLEGAL POSITION");
    return false;
  }
  else
  {
    if(P == L->Last + 1)
    {
      L->Data[P] = X;
    }
    else
    {
      for(int i = L->Last; i >= P; i--)
      {
        L->Data[i + 1] = L->Data[i];
      }
      L->Data[P] = X;
    }
    L->Last++;
    return true;
  }
}
bool Delete( List L, Position P )
{
  if(P < 0 || P > L->Last)
  {
    printf("POSITION %d EMPTY", P);
    return false;
  }
  else
  {
    for(int i = P + 1; i <= L->Last; i++)
    {
      L->Data[i - 1] = L->Data[i];
    }
    L->Last--;
    return true;
  }
}
