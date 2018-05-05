#include <stdio.h>

int main(void)
{
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        double temp;
        if(a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if(a > c)
        {
            temp = c;
            c = a;
            a = temp;
        }
        if(b > c)
        {
            temp = b;
            b = c;
            c = temp;
        }
        printf("%.2f %.2f %.2f\n", a, b, c);
    }
    return 0;
}
