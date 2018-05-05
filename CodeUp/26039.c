#include <stdio.h>

int main(void)
{
    int arr[10];
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ins;
    scanf("%d", &ins);
    int pt = 8;
    while(arr[pt] > ins)
    {
        arr[pt + 1] = arr[pt];
        pt--;
    }
    arr[pt + 1] = ins;
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
