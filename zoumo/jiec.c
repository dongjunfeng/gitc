#include <stdio.h>

int main (void)
{
    int i = 1;
    int sum = 1;
    int ji = 1;

    for(i = 1; i <= 10; i++)
    {
        ji = ji * i;
        sum = sum + ji;
    }

        printf("sum = %d\n",sum);
    


    return 0;
}
