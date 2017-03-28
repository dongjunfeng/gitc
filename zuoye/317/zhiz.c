#include <stdio.h>

int main(void)
{
  int a[10] ={1, 2, 4, 12, 43, 54, 12, 123, 43, 12};
  int i;
  char *p;
  p = a;

  for(i = 0; i < 10; i++)
  {
    printf("%d  ", *p);
    p = p + 4;
  }
  printf("\n");
  return 0;
}
