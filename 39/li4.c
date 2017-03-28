#include <stdio.h>
#include <math.h>

int main(void)
{
  char ch[100] = "hello";
  char str[100] = "world";
  int i = 5;

  sprintf(ch,"%d",i);
  printf("%d\n",ch[0]);

  return 0;
}
