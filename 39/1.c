#include <stdio.h>
#include <string.h>

int my(const char *a)
{
  int i;
  int sum;

  for(i = 0;a[i] != 0; i++)
  {
    sum += 1;
  }
  return sum;
}

int main(int argc, const char *argv[])
{
  char b[30] = "hello world";
  int len;
  len = my(b);
  printf("sum = %d\n", len);

  return 0;
}
