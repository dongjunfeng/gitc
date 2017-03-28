#include <stdio.h>

int main(void)
{
    int a = 23;
    int b = 21;
    int c = 34;

    if(a < b)
    {
        if(a < c)
        {
            printf("min = a\n");
        }
        else
        {
            printf("min = c\n");
        }
    }
    else
    {
        if(b < c)
        {
            printf("min = b\n");
        }
        else
        {
            printf("min = c\n");
        }
    }
    return 0;
}
