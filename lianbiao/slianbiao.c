#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Books
{
  struct Books * next;
  struct Books * prior;
  int book_id;
}node;

int insert(struct Books * p, int val);
void show(node * head);
node *creat(int val);
void del(node * h, int val);
int insert1(struct Books * h, int val, int val1);

int main()
{
  struct Books *head;
  head = creat(0);
  insert(head, 13);
  insert(head, 14);
  insert(head, 15);
  insert(head, 16);
  insert(head, 17);
  show(head);
  printf("---------------\n");
  del(head, 14);
  show(head);
  printf("---------------\n");
  insert1(head, 16, 20);
  show(head);
  return 0;
}

node *creat(int val)
{
  node * p = NULL;
  p = malloc(sizeof(node));
  if(p == NULL)
  {
    printf("error!\n");
  }
  p -> book_id = val;
  p -> next = p;
  p -> prior = p;
  return p;
}
int insert(struct Books * p, int val)
{
  struct Books * p1 = NULL;
  p1 = malloc(sizeof(struct Books));

  if(p1 == NULL)
  {
    printf("error!\n");
  }
  p1 -> book_id = val;

  p -> next -> prior= p1;
  p1 -> next = p -> next;
  p -> next = p1;
  p1 -> prior = p;

  return 0;
}

void show(node * head)
{
  node *p = head -> next;
  while (p != head)
  {
    printf("head -> id = %d\n", p -> book_id);
    p = p -> next;
  }
}

void del(node * h, int val)
{
  node * p = NULL;
  node * p1 = NULL;
  p = h;
  while(p -> book_id != val  && p != NULL)
  {
    p1 = p;
    p = p -> next;
  }

  p1 -> next = p -> next ;
  p -> next -> prior =  p -> prior;
  free(p);
}

int insert1(struct Books * h, int val, int val1)
{
  node * p = NULL;
  p = malloc(sizeof(node));
  p -> book_id = val1;
  while(h != NULL && h -> book_id != val)
  {
    h = h -> next;
  }
  p -> prior = h;
  p -> next = h -> next;
  h -> next = p;
  h -> next -> prior = p;
  return 0;
}
