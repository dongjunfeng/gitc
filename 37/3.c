#include <stdio.h>

int main(void)
{
  int a[5] = {1, 23, 10, 89, 35};
  int i;
  int j = 0;

  for(i = j + 1; i < 5; i++)
  {
    if(a[j] < a[i])
    {
      j = i;
    }
  }
  printf("max = %d\n", a[j]);
  return 0;
}
