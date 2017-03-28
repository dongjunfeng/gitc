#include <stdio.h>

int main()
{
    int a = 65465;
    int b = 46843;
    int c = 12434;

    printf("a = %d, b = %d, c = %d\n",a, b, c);

    if( a < b )
    {
        if( a < c )
        {
            printf("a min = %d\n" ,a);
        }
        else
        {
            printf("c min = %d\n" ,c);
        }
        if( b > c )
        {
            printf("b is max = %d", b);
        }
        else
        {
            printf("c is max = %d", c);
        }
        
    }
        else
        {
            if( b < c ){
                printf("b min = %d\n" ,b);
            }
            else{
                printf("c min = %d\n" ,c);
            }
            if( c > a )
            {
                printf("c is max = %d\n", c);
            }
            else
            {
                printf("a is max = %d\n", a);
            }
        }
        return 0;
}
