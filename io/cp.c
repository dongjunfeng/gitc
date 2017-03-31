#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
  int fdr, fdw;
  int bytes;
  char buf[16] = {0};
  if((fdr = open(argv[1], O_RDONLY)) < 0)
  {
    printf("fail to open the fdr\n");
    return -1;
  }
  if((fdw = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0)
  {
    printf("fail to open the fdw\n");
    return -1;
  }
  while((bytes = read(fdr, buf, sizeof(buf))) > 0)
  {
    write(fdw, buf, bytes);
  }
  close(fdr);
  close(fdw);
  return 0;
}
