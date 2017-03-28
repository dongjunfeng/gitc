#include <stdio.h>

int main(void)
{
    int i = 123;
    int j;

    while(i != 0)
    {
        j = i % 10;

        printf("%d",j);

        i = i / 10;
    }
    printf("\n");
    return 0;
}
