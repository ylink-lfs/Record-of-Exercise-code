#include <stdio.h>

int main(void)
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
