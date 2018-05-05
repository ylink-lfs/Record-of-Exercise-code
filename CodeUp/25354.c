#include <stdio.h>

int main(void)
{
    double profit;
    while(scanf("%lf", &profit) == 1)
    {
        double bonus = 0;
        if(profit < 100000)
        {
            bonus += profit * 0.1;
        }
        else if(profit >= 100000 && profit < 200000)
        {
            bonus += 10000 + (profit - 100000) * 0.075;
        }
        else if (profit >= 200000 && profit < 400000)
        {
            bonus += 10000 + 7500 + (profit - 200000) * 0.05;
        }
        else if (profit >= 400000 && profit < 600000)
        {
            bonus += 10000 + 7500 + 10000 + (profit - 400000) * 0.03;
        }
        else if (profit >= 600000 && profit < 1000000)
        {
            bonus += 10000 + 7500 + 10000 + 3000;
        }
        else
        {
            bonus += 10000 + 7500 + 10000 + 3000 + 6000 + (profit - 1000000) * 0.01;
        }
        printf("%.2lf\n", bonus);
    }
    return 0;
}
