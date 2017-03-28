#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();
    int sum = 0;
    int zifu = 0;
    while (!(c == EOF))
    {
        if(c == 10)
        {
           sum ++;
        }
        if(c >= 0 && c <= 127)
        {
            zifu ++;
        }
        c = getchar();
                  
    }
    
    printf(" %d  ", sum);
    printf(" %d\n", zifu);

    return 0;

}


/*#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();
    while(c != EOF)
    {

        if(c == 32)
       {
          printf("%%20\t");
       }  
        c = getchar();
    }

    printf("\n");

    return 0;
}*/
















