#include <stdio.h>

int main(void)
{
    int sum = 0;
    for(int i = 0; i < 101; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
