#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();
    int temp, zifu;

    while(c != EOF)
    {
        if(c == 10)
        {
            temp ++;
        }
        if(c >= 0 && c <= 127)
        {
            zifu ++;
        }
        c = getchar();
    }
    printf("temp = %d  zifu = %d\n", temp, zifu);
    return 0;
}
