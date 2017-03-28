#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();

    while(c != EOF)
    {
        if(c >= 60 && c <= 90)
        {
            printf("%c", c + 32);
            c++;
        }
        if(c >= 97 && c <= 122)
        {
            printf("%c", c - 32);
            c--;
        }
        c = getchar();

    }
    printf("\n");
    return 0;
}
