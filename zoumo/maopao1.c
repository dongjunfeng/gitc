#include <stdio.h>

int main(void)
{
  int a[6] = {21, 123, 354, 34, 12, 54};
  int i, j, h;
  int tmp;

  for(i = 0; i < 6; i++)
  {
    h = i;
    for(j = h + 1; j < 6 ; j++)
    {
      if(a[h] < a[j])
      {
        h = j;
      }
    }
      tmp = a[i];
      a[i] = a[h];
      a[h] = tmp;

  }
  for(i = 0; i < 6; i++)
  {
    printf("a[%d] = %d | ", i, a[i]);
  }
  printf("\n");
  return 0;
}
