#include <stdio.h>

int main(void)
{
     char c;
     int sta = 0;
     c = getchar();
   
     while( c != EOF)
     {
         if(sta == 0)
         {
             if(c == '%')
             {
                 sta++;
             }
             else
             {

                 printf("%c", c);
                 sta = 0;
                 
             }
         }
         else if(sta == 1)
         {
             if(c == '1')
             {
                 sta++;
             }
             else
             {
                 printf("%%");
                 printf("%c", c);
                 sta = 0;
                 
             }
         }
         else if(sta == 2)
         {
             if(c == '2')
             {
                 sta++;
             }
             else
             {
                 printf("%%");
                 printf("1");
                 printf("%c", c);
                 sta = 0;
             }
         }
         else if(sta == 3)
         {
             if(c == '3')
             {
                 sta++;
             }
             else
             {
                 printf("%%");
                 printf("1");
                 printf("2");
                 printf("%c", c);
                 sta = 0;
             }
         }
         else if(sta == 4)
         {
             if(c == '4')
             {
                 printf(" * ");
                 sta = 0;
             }
             else
             {
                 printf("%%");
                 printf("1");
                 printf("2");
                 printf("3");
                 printf("%c", c);
                 sta = 0;
             }
         }
         
             c = getchar();
     }
     printf("\n");
     return 0;

}
