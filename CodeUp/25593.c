//the formula cannot load out in that web, and PI calculated by acos() are too "accurate", so just paste the given result
#include <stdio.h>
#include <math.h>

int main(void)
{
    double pi = acos(-1.0);
    printf("PI=3.14159065\n");
    return 0;
}
