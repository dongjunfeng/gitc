#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();
    int temp = 0;

    while(c != EOF)
    {
        if(c == 10)
        {
            temp ++;
        }
        c = getchar();
    }
    
    printf("temp = %d\n", temp);
    return 0;
}
