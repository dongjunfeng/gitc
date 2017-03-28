#include <stdio.h>

int main(void)
{
  int a = 10;
  int *p;
  printf("a = %d\t &a = %p\n", a, &a);
  p = &a;
  printf("p = %d\t &p = %p\n", *p, p);
  printf("int = %lu\n", sizeof(int));
  return 0;
}
