#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
  int i, j;
  i = 22;
  j = 11;

  if(argv[1][0] == '+')
  {
      printf("%d\n",i + j);
  }
  if(argv[1][0] == '-')
  {
      printf("%d\n",i - j);
  }
  if(argv[1][0] == '*')
  {
    printf("%d\n", i * j);
  }
  if(argv[1][0] == '/')
  {
    printf("%d\n", i / j);
  }
  else if(argv[1][0] == '%')
  {
    printf("%d\n", i % j);
  }

  return 0;
}
