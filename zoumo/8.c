#include <stdio.h>

int main(void)
{
    int a = 1 ;
    int sum = 0;
    int ji = 1;

    for(; a <= 10; a++)
    {
        ji = ji * a;
        sum = sum + ji;
        
    }

        printf("sum = %d\n", sum);
    return 0;
}
