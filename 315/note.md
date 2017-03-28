## system  函数

```sh
示例代码：
#include <stdlib.h>
int system(const char *command);
功能： 就是执行一个命令 
比如： system(" cp  file  newfile");完成文件拷贝
```
## fgets 函数

```sh
示例代码:
char *fgets(char *s, int size, FILE *stream);
功能： 就是一次读取一行,遇到'\n'就立刻返回. 当返回值为NULL时表示文件读取结束
参数： s , 用于存放读取的字符串(传递数组名即可)
      size, 指定读取一次最多读取到的字节个数
      stream, 直接填写stdin即可      
比如： fgets(buf, 64, stdin); 从标准输入读入一行      
```
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char buf[32];
  char direct[64] = "mv ";

  while (fgets(buf, 32, stdin) != NULL)
  {
    buf[strlen(buf) -1] = '\0';           //将读出来的文件字符末尾的"/n"去掉，加上“\0”，
    strcat(direct, buf);                  //将buf 拼接到 direct。  ”mv buf“
    strcat(buf, "-1");                     //将‘-1’拼接到buf。  “buf-1”                
    strcat(direct, " ");                   //将加了mv的字符串再加上一个空格。  “mv buf ”
    strcat(direct, buf);                   //将两个字符串拼接。    “mv buf buf-1”
    printf("%s\n", direct);                // 输出拼接好的字符串                                  
    
    system(direct);                         // 运行字符串的命令
    strcpy(direct, "mv \0");                // 将更改好的字符串清0更改为初始状态。    “mv ”       
  }

  return 0;
}
```
***
