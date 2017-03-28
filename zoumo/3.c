#include <stdio.h>

int main(void)
{
    int a = 212324;
    int sum = 0;

    while(a)
    {
        a = a / 10;
        sum = sum + 1;
    }
    printf("sum = %d\n", sum);

    return 0;
}
