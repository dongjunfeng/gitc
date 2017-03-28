#include <stdio.h>

int main(void)
{    
    int a, b, c;

    for (a = 50; a <= 100; a++)
    {
        for (b = 2; b < a; b++)
        {
            if(a % b == 0)
            {
                break;
            }
        }
        if(b == a)
        {
            printf("%d = 1 * %d\n", a, a);
            continue;
        }
        c = a;
        printf("%d = ", c);
        for (b = 2; b < a; b++)
        {
            while(c % b == 0)
            {
                printf("%d ", b);
                c = c / b;
                if(c != 1)
                {
                printf(" * ");
                }
            }
        }
        printf("\n");
        
    }

    return 0;
}
