#include <stdio.h>

int main(void)
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 9; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
