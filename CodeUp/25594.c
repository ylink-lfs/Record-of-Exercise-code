#include <stdio.h>

int main(void)
{
    int fib[55] = {0, 1, 1};
    int i;
    for(i = 3; i < 55; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%d\n", fib[n]);
    }
    return 0;
}
