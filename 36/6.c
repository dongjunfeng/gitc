#include <stdio.h>

int main(void)
{
    char c;
    c = getchar(); 
    int  sta = 0;

    while(c != EOF)
    {
        if(sta == 0)
        {
            if(c == 'a')
            {
                sta ++;
            }
            else
            {
                printf("%c", c);
                sta = 0;
            }
        }
        else if(sta == 1)
        {
            if(c == 'b')
            {
                sta++;
            }
            else
            {
                printf("a");
                printf("%c", c);
                sta = 0;
            }
        }
        else if(sta == 2)
        {
            if(c == 'c')
            {
                sta++;
            }
            else
            {
                printf("a");
                printf("b");
                printf("%c", c);
                sta = 0;
            }
        }
        else if(sta == 3)
        {
            if(c == 'a')
            {
                sta++;
            }
            else
            {
                printf("a");
                printf("b");
                printf("c");
                printf("%c", c);
                sta = 0;
            }
        }
        else if(sta == 4)
        {
            if(c == 'b')
            {
                printf("*");
                sta = 0;
            }
            else
            {
                printf("a");
                printf("b");
                printf("c");
                sta = 1;
            }
        }
        c = getchar();
    }
    printf("\n");
    return 0;
}
