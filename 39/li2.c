#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  char dest[32];
  char src[32] = "This is a test";

  strcpy(dest , src);
  printf("%s\n",dest);
  return 0;
}

/*#include <string.h>

int main(int argc, const char *argv[])
{
  char dest[64] = "hello";
  char src[32] ="  world!";
  strcat(dest, src);
  printf("%s\n", dest);

  return 0;
}*/

/*#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  char str1[32] = "asdqwe";
  char str2[32] = "asd";
  int ret = strcmp(str1, str2);

  if (ret > 0)
  {
    printf("str1 > str2 %d\n", ret);
  }
  else if(ret < 0)
  {
    printf("str1 < str2 %d\n", ret);
  }
  else
  {
    printf("str1 = str2 %d\n", ret);
  }

  return 0;
}
*/
