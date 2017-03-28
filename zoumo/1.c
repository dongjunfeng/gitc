#include <stdio.h>

int main(void)
{
    int a = 23, b = 223, c = 224;

    if(a > b)
    {
        if(a > c)
        {
            printf("max = a\n");
        }
        else
        {
            printf("max = c\n");
        }   
    }
    else
    {
        if(b > c)
        {
            printf("max = b\n");
        }
        else
        {
            printf("max = c\n");
        }
    }
    return 0;
}
