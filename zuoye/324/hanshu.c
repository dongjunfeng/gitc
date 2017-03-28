#include <stdio.h>
#include <ctype.h>

int my(void)
{
  char c;
  int sta = 0;
  while ((c = getchar()) != EOF)
  {
      if(sta == 0)
      {
        if (c == '%')
        {
          sta++;
        }
        if(c == 32)
        {
          printf("%%20");
        }
        else{
          sta = 0;
          printf("%c", c);
        }
      }
      else if(sta == 1)
      {
        if(c == '2')
        {
          sta++;
        }
        else if(c == 32)
        {
          printf("%%%%20");
          sta = 0;
        }
        else
        {
          printf("%%");
          printf("%c", c);
          sta = 0;
        }
      }
      else if (sta == 2)
      {
        if(c == '0')
        {
          printf(" ");
        }
        else if(c == 32)
        {
          printf("%%2%%20");
        }
        else
        {
          printf("%%");
          printf("2");
          printf("%c", c);
        }
        sta = 0;
      }
    }
  return 0;
}
int main(int argc , char const *argv[])
{
  my();
  return 0;
}
