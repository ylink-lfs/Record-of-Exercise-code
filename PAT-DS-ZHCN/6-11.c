void PreorderPrintLeaves( BinTree BT )
{
  if(BT == NULL)
    return;
  else if(BT->Left == NULL && BT->Right == NULL)
  {
    printf(" %c", BT->Data);
  }
  else
  {
    PreorderPrintLeaves(BT->Left);
    PreorderPrintLeaves(BT->Right);
  }
}
