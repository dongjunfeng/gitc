#include <stdio.h>
#include <stdlib.h>

typedef char typedata;
typedef struct node
{
  typedata data;
  struct node *lchild, *rchild;
}NODE;

NODE *createBiTree()         //初始化二叉树
{
  char chdata = 0;
  NODE *p = NULL;
  scanf("%c",&chdata);
  if(chdata == '#')
  {
    p = NULL;
  }
  else
  {
    p = (NODE*)malloc(sizeof(NODE) + 1);   //分配内存
    p -> data = chdata;
    p -> lchild = createBiTree();         //递归产生二叉树
    p -> rchild = createBiTree();
  }
  return p;
}

int previsitbitree(NODE * i)      //前序遍历二叉树 根左右
{
  if(i)
  {
    printf("%c", i -> data);
    previsitbitree(i -> lchild);
    previsitbitree(i -> rchild);
  }
  return 0;
}

int invisitbitree(NODE * i)              //中序遍历二叉树 左根右
{
  if(i)
  {
    invisitbitree(i -> lchild);
    printf("%c", i -> data);
    invisitbitree(i -> rchild);
  }
  return 0;
}

int postvisitbitree(NODE* i)               //后序遍历  左右根
{
  if(i)
  {
    postvisitbitree(i -> lchild);
    postvisitbitree(i -> rchild);
    printf("%c", i -> data);
  }
  return 0;
}

int main(void)
{
  NODE * h;
  h = createBiTree();
  previsitbitree(h);
  printf("\n");
  invisitbitree(h);
  printf("\n");
  postvisitbitree(h);
  return 0;
}

输入 ABC##DE#G##F###
输出 ABCDEGF
    CBEGDFA
    CGEFDBA
