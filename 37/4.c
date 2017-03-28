#include <stdio.h>

int main(void)
{
  char a;
  a = getchar();
  int shuzi = 0;
  int zimu = 0;

  while( a != EOF )
{
     if(a >= 48 && a <= 57)
     {
        shuzi = shuzi + 1;
     }
     if(a >= 97 && a <= 122)
     {
        zimu = zimu + 1;
     }
     a = getchar();
}
  printf("shuzi = %d\n", shuzi);
  printf("zimu = %d\n", zimu );
  return 0;
}
