#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char buf[32];
  char direct[64] = "mv ";

  while (fgets(buf, 32, stdin) != NULL)
  {
    buf[strlen(buf) - 1] = '\0';
    strcat(direct, buf);
    strcat(buf, "-1");
    strcat(direct, " ");
    strcat(direct, buf);
    printf("%s\n", direct);

    system(direct);
    strcpy(direct, "mv \0");
  }

  return 0;
}
