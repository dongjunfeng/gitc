#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  char str[] = "hello world";
  int len;

  len = strlen(str);
  printf("strlen(str) = %d\n", len);
  printf("sizeof(str) = %lu\n", sizeof(str));
  printf("sizeof(len) = %lu\n", sizeof(len));

  return 0;
}
