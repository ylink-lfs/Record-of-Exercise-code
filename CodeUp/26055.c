#include <string.h>
#include <stdio.h>

int main(void)
{
    char s1[100];
    char s2[100];
    char s3[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    fgets(s3, 100, stdin);
    s1[strlen(s1) - 1] = s2[strlen(s2) - 1] = s3[strlen(s3) - 1] = 0;
    printf("%s\n", strcmp(s1, s2) > 0 ? strcmp(s1, s3) > 0 ? s1 : s3 : strcmp(s2, s3) > 0 ? s2 : s3);
    return 0;
}
