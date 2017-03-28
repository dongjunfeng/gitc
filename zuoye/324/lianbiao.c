#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}linknode, *linklist;

int main()
{
  linklist p1;
  /*struct node *p1 = NULL;*/
  p1 = malloc(sizeof(struct node));
  if(p1 == NULL){}
  p1->data = 10;
  p1->next = NULL;

  linklist head;
  /*struct node *head = NULL;*/
  head = malloc(sizeof(struct node));
  head->data = 20;
  p1->next = head;
  head->next = NULL;
  printf("%d\n",p1->data);
  printf("%d\n",head->data);
  //free(head);
  return 0;
}
