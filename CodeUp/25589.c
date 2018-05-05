#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0;
    int index = 1;
    while(scanf("%d", &n) == 1)
    {
        while(1)
        {
            sum += index;
            index++;
            if(index == n + 1)
              break;
        }
        printf("%d\n", sum);
    }
    return 0;
}
