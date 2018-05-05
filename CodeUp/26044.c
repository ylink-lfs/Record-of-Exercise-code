#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    while((ch = getchar()) != '\n' && ch != -1)
    {
        if(islower(ch))
        {
            ch = (26 - (ch - 'a' + 1) + 1) + 'a' - 1;
        }
        else if (isupper(ch))
        {
            ch = (26 - (ch - 'A' + 1) + 1) + 'A' - 1;
        }
        else
        {
            ;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
