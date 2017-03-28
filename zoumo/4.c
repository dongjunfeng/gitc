#include <stdio.h>

int main(void)
{
    int hour = 12;
    int min = 5;
    int x = hour - 12;

    if(x > 0)
    {
        printf("%d : %02d PM\n", x, min);
    }
    if(x < 0)
    {
        printf("%d : %02d AM\n", hour, min);
    }
    if(x == 0)
    {
        printf("%d : %02d PM\n", hour, min);
    }
    return 0;
}
