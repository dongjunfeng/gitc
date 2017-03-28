#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  char cmd[100];
  if(argc == 3)
  {
    sprintf(cmd,"mv %s %s\n", argv[1], argv[2]);
    system(cmd);
  }
  else
  {
    printf("Error!!!\n");
  }
  return 0;
}
