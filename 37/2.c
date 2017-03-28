#include <stdio.h>

int main(void)
{
  int a[5] = {23, 45, 12, 56, 67};
  int i;

  for(i = 4; i >= 0; i--)
  {
    printf(" %d", a[i]);
  }
  printf("\n");
  return 0;
}
