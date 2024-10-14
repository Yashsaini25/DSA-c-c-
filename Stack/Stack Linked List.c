#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
 int data;
 struct stack *next;
}s;

void push(s**);
void pop(s**);
void display(s*);

int main()
{
s *top=NULL;
int ch;

do
{
 int ch;
 scanf("%d",&ch);
 switch (ch)
 {
  case 1:
  push(&top);
  break;
  case 2:
  pop(&top);
  break;
  case 3:
  display(top);
  break;
 }
}while(ch<=3);

return 0;
}

void push(s** top)
{
 int v;
 s* p=(s*)malloc(sizeof(s));
 
 if(p==NULL)
 printf("Memeory allocation failed");
 
 else
 {
  printf("Enter a value to be pushed: ");
  scanf("%d",&v);
  p->data=v;
  p->next=*top;
  *top=p;
 }
}
 
void pop(s** top)
{ 
 s *p=NULL;
 if(*top!=NULL)
{
 printf("value: %d\n",(*top)->data);
 p=*top;
 (*top)=(*top)->next;
 free(p);
}
else printf("Stack is empty");
}

void display(s* top)
{
 if(top==NULL)
 printf("Stack is empty");
 while(top!=NULL)
{
 printf("value: %d\n",top->data);
 top=top->next;
}
}
