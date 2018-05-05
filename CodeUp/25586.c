#include <stdio.h>

int main(void)
{
    int sum = 0;
    int index = 1;
    while(index <= 100)
    {
        sum += index;
        index++;
    }
    printf("%d\n", sum);
    return 0;
}
