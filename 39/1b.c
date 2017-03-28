#include <stdio.h>
#include <string.h>

void my(char *a, const char *b)
{
  int i, j;
  int tmp;
  for(i = 0; a[i] != 0; i++)
  {
    tmp++;
  }
  for(j = 0; b[j] != 0; j++)
  {
  a[tmp + j] = b[j];
  }
}


int main(int argc, const char *argv[])
{
  char dest[64] = "hello world";
  char src[32] = " this is a tast";
  my(dest, src);
  printf("%s\n", dest);
  return 0;
}
