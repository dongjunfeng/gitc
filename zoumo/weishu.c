#include <stdio.h>

int main(void)
{
    int x = 3242;
    int sum = 0;

    for(;x != 0;)
    {
      x = x / 10;
      sum = sum + 1;
      
    }
    printf(" sum = %d\n", sum);

    return 0;
}
