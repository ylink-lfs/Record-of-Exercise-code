#include <stdio.h>

int triangle[55][55];

int main(void)
{
    for(int i = 1; i < 55; i++)
    {
        triangle[i][i] = triangle[i][1] = 1;
    }
    for(int i = 3; i < 40; i++)
    {
        for(int j = 2; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    int n;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                printf("%d", triangle[i][j]);
                if(j == i)
                {
                    putchar('\n');
                }
                else
                {
                   putchar(' ');
                }
            }
        }
    }
    return 0;
}
