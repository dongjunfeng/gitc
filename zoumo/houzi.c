#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 1;

    for(i = 1; i < 10; i++)
    {
        sum = (sum + 1) * 2;
        printf("sum = %d\n", sum);
    }

    return 0;
}
