#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
  DIR *dir;
  dir = opendir(".");
  if(dir == NULL)
  {}
  struct dirent * dt;
  dt = readdir(dir);
  printf("%s\n", dt -> d_name);
  int closedir(DIR *dirp);
  return 0;
}
