#include <stdio.h>

int main(void)
{
    int x = 4567;
    int a, b, c, d;

     a = x / 1000;
     b = x / 100 % 10;
     c = x / 10 % 10;
     d = x % 10;

    printf("a = %d b = %d c = %d d = %d\n",a, b, c, d);

    return 0;
}
