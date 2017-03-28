#include <stdio.h>

int main(void)
{
    int c = 1;
    int sum = 1;

    for(c = 1; c < 10; c++)
    {
        sum = (sum + 1) * 2;
    }
    printf("sum = %d\n", sum);

    return 0;
}
