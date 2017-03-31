#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
  DIR * dir;
  struct dirent * dt;
  if((dir = opendir(".")) == NULL)
  {
    printf("error!\n");
    return -1;
  }
  while((dt = readdir(dir)) != NULL)
  {
    if(dt->d_name[0] != '.')
    {
      printf("%s\n", dt->d_name);
    }
  }
  closedir(dir);
  return 0;
}
