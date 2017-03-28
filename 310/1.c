#include <stdio.h>

void swap(int *p, int *q)
{
  int a;
  a = *p;
  *p = *q;
  *q = a;
}

int main(void)
{
  int i = 10;
  int j = 20;
  swap (&i, &j);
  printf("i = %d j = %d\n", i, j);
  return 0;
}
