
#include <stdio.h>

#include <math.h>



int main(void)

{

    double a, b, c;

    while(scanf("%lf%lf%lf", &a, &b, &c) == 3)

    {

        double factor1 = -b;

        double factor2 = b * b - 4 * a * c;

        double factor3 = 2 * a;
        
        if(factor2 < 0)
        {
            printf("No real roots!\n");
            continue;
        }
        else
        {
            factor2 = sqrt(factor2);
        }

        double r1 = (factor1 + factor2) / factor3;

        double r2 = (factor1 - factor2) / factor3;

        printf("r1=%7.2f\nr2=%7.2f\n", r1, r2);

    }

    return 0;

}
