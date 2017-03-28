#include <stdio.h>

int main(void)
{
  int a[5] = {1, 2, 3, 1, 1};
  int b[5] = {0};
  int i, j, tmp;

  for(i = 0; i < 5; i++)
  {
    tmp = i;
    for(j = i + 1; j < 5; j++)
    {
      if(a[tmp] == a[j])
      {
        b[tmp] = 1;
        b[j] = 1;
      }
    }
  }
  for(i = 0; i < 5; i++)
  {
      if(b[i])
      {
         printf("a[%d] ", i);
      }
  }
  printf("\n");
  return 0;
}
