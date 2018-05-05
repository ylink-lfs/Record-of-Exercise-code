#include <stdio.h>

int main(void)
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) == 3)
    {
        printf("%d\n", a > b ? a > c ? a : c : b > c ? b : c);
    }
    return 0;
}
