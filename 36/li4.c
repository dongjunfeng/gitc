#include <stdio.h>

int main(void)
{
    char s[1];
    char ch[5] = "abcde";
    s[0] = 'a';
    int i = 0;


    for(i = 0; i < 8; i++)
        putchar(s[i]);
    printf("\n");
    printf("%s\n", s);

    return 0;
}

