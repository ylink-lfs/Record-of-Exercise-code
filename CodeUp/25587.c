#include <stdio.h>

int main(void)
{
    int sum = 0;
    int index = 1;
    do
    {
        sum += index++;
    } while(index < 101);
    printf("%d\n", sum);
    return 0;
}
