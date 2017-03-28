#include <stdio.h>
#include <string.h>

int my(char *a, const char *b)
{
  int i;
  int j;

  for(i = 0;a[i] && b[i] != 0;i++)
  {
    j = a[i] - b[i];
    if(a[i] != b[i])
    {
      break;
    }
  }
  return j;
}

int main(int argc, const char *argv[])
{
  char str1[32] = "asdzcsa";
  char str2[32] = "asdsdzcq";
  int ret;
  ret = my(str1, str2);
  printf("%d\n", ret);
  return 0;
}
