#include <stdio.h>

int main(void)
{
    int m1[2][3];
    int m2[3][2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            m2[i][j] = m1[j][i];
            printf("%d", m2[i][j]);
            if(j == 1)
            {
                putchar('\n');
            }
            else
            {
                putchar(' ');
            }
        }
    }
    return 0;
}
