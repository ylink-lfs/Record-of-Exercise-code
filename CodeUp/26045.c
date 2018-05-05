#include <stdio.h>
#include <string.h>
int main(void)
{
    char s1[100];
    char s2[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    s1[strlen(s1) - 1] = s2[strlen(s2) - 1] = 0;
    int c1 = 0;
    int c2 = 0;
    while(s1[c1] != 0 && s2[c2] != 0 && s1[c1] == s2[c2])
    {
        c1++;
        c2++;
    }
    int subtract;
    subtract = s1[c1] - s2[c2];
    printf("%d\n", subtract);
    return 0;
}
