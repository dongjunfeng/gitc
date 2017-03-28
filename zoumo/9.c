#include <stdio.h>

int main (void)
{
    int x, y, z;
    int i;
    int sum = 0;

    for(i = 100; i <= 999; i++)
    {
        x = i % 10;
        y = i / 10 % 10;
        z = i / 100;
        sum = x * x * x + y * y * y + z * z * z;

        if(sum == i)
        {
            printf("i = %d\n", i);
        }
    } 
    return 0;
}
