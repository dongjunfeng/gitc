#include <stdio.h>

int main(void)
{
    int a[7] = {12, 24, 1, 34, 55, 2, 77};
    int i,j;
    int tmp;
    int max = 7;

    for(i = 0; i < max; i++)
    {
        for(j = 0; j < max - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
   for(i = 0; i < max; i++)
   {
        printf("a[%d] = %d | ", i, a[i]);
   }
    printf("\n");

    return 0;
}
