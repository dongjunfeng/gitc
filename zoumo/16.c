#include <stdio.h>

int main(void)
{
    int a, b, c;

    for(a = 1; a <= 1000; a++)
    {
        c = 0;
        for(b = 1; b < a; b++)
        {
            if(a % b == 0)
            {
                c = c + b;
            }
        }
        if(c == a)
        {
            printf("wanshu %d\n", a);
        }

    }

    return 0;
}
