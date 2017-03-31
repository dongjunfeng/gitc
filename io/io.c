#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fd;
  char buf[64] = "helloworld";
  fd = open("./file", O_WRONLY|O_CREAT, 0666);
  int len;
  len = write(fd, buf, strlen(buf));
  printf("len = %d\n",len);
  int close(int fd);
  return 0;
}
