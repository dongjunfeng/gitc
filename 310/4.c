#include <stdio.h>

int main(void)
{
  float a, b, i, j;
  float sum, sum1, sum2;
  int n = 10;

  for(a = 1; a <= n; a = a + 2)
  {
    i = 1 / a;
    sum = sum + i;
  }
  for(b = 2; b <= n; b = b + 2)
  {
    j = 1 / b;
    sum1 = sum1 + j;
  }
  sum2 = sum - sum1;
  printf("sum = %f\n", sum2);

  return 0;

}
