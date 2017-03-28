#include <stdio.h>

int main(void)
{
   int i ;
   int j ;
   int sum;

   for(i > 2; i <= 1000; i++)
   {
       for(j = 2; j < i; j++)
       {
           while(i % j == 0)
           {
               printf("%d", j);

               i = i / j;
               sum = sum + j;
           }
       }
       i = sum;
       printf("%d\t", i);
   }
    return 0;
}
