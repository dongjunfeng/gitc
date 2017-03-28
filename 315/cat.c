#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  char i[64];
  if(argc == 2)
  {
    sprintf(i,"cat %s\n", argv[1]);
    system(i);
  }
  else
  {
    printf("error\n");
  }
  return 0;
}
