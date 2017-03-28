#include <stdio.h>

int main(void)
{
  int a[9] = {1, 2, 3, 3, 2, 1, 1, 2, 3};
  int b[9] = {0};
  int i, j, tmp;

  for(i = 0; i < 9; i++)
  {
    tmp = i;
    for(j = i + 1; j < 9; j++)
    {
      if(a[tmp] == a[j])
      {
        b[tmp] = a[j];
        b[j] = a[j];
      }
    }
  }
  for(i = 1; i < 4; i++)
  {
    printf("%d = ", i);
    for(j = 0; j < 9; j++)
    {
      if(b[j] == i)
      {
        printf("a[%d]  ", j);
      }
    }
    printf("\n");
  }
  return 0;
}
