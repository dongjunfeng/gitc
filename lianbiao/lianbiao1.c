#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Books
{
  struct Books *next;
  int book_id;
}node;

int insert(struct Books * head, int val);
void show(struct Books * head);
struct Books * delete(struct Books * p, int val);
int insert1(struct Books * p, int val, int val1);

int main()
{
  struct Books head;
  struct Books * p2;
  p2 = &head;
  head.book_id = 100;
  head.next = NULL;
  insert(&head, 101);
  insert(&head, 102);
  insert(&head, 103);
  insert(&head, 104);
  insert(&head, 105);
  insert(&head, 106);
  show(&head);
  insert1(&head, 100, 107);
  printf("------------------\n");
  show(&head);
  delete(&head, 104);
  printf("------------------\n");
  show(&head);

  return 0;
}

int insert(struct Books * p1, int val)
{
  struct Books * p = NULL;
  p = malloc(sizeof(struct Books));
  if(p == NULL)
  {
    printf("error\n");
    return -1;
  }
  p->book_id = val;
  p->next = NULL;
  while((p1 -> next) != NULL)
  {
    p1 = p1 -> next;
  }
  p1 -> next = p;
  return 0;
}

void show(struct Books * head)
{
  while ((head) != NULL)
  {
    printf("head -> id = %d\n", head -> book_id);
    head = head -> next;
  }
}

struct Books * delete(struct Books * p, int val)
{
  struct Books * cur = NULL;
  struct Books * prev = NULL;

  cur = p;

  if(cur->book_id == val)
  {
    cur = cur -> next;
    free(cur);
  }
  else{
    while(cur != NULL && cur -> book_id != val)
    {
      prev = cur;
      cur = cur -> next;
    }
    if(cur != NULL)
    {
      prev -> next = cur -> next;
      free(cur);
    }
   }
  return p;
}
int insert1(struct Books * p, int val, int val1)
{
  struct Books * p1 = NULL;
  p1 = malloc(sizeof(struct Books));

  p1 -> book_id = val1;

  while(p != NULL && p -> book_id != val)
  {
    p = p -> next;
  }
  p1 -> next = p -> next;
  p -> next = p1;
  return 0;
}
