#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();

    while(c != EOF)
    {
        if(c == 32)
        {
            printf("%%20", c);
        }
        else
        {
            printf("%c");
        }
        c = getchar();
    }
    printf("\n");
    return 0;
}

