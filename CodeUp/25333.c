#include <stdio.h>

int main(void)
{
    double a, b;
    while(scanf("%lf%lf", &a, &b) == 2)
    {
        if(a < b)
        {
            printf("%.2f %.2f\n", a, b);
        }
        else
        {
            printf("%.2f %.2f", b, a);
        }
    }
    return 0;
}
