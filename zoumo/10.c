#include <stdio.h>

int main(void)
{
    int i = 3243;
    int sum = 0;

    while(i != 0)
    {
        i = i / 10;
        sum = sum + 1;
    }
    printf("sum = %d\n", sum);

    return 0;
}
