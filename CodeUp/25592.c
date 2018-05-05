#include <stdio.h>

int main(void)
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%3d", (i + 1) * (j + 1));
        }
        putchar('\n');
    }
    return 0;
}
