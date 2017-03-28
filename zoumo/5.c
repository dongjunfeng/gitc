#include <stdio.h>

int main(void)
{     
    int a = 23;
    int b = 11;
    int c = 55;
    int max = 0;

    max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    {
        printf("max = %d\n",max);
    }

    return 0;
}
