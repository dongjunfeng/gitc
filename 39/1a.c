#include <stdio.h>
#include <string.h>

void my(char *a, const char *b)
{
  int i = 0;
  while(b[i] != 0)
  {
    a[i] = b[i];
    i++;
  }

}

int main(int argc, const char *argv[])
{
  char dest[64];
  char src[32] = "This is a test";
  my(dest, src);
  printf( "%s\n", dest);
  return 0;
}
