#include <stdio.h>
#include <stdlib.h>

typedef struct dlist
{
 int data;
 struct dlist* prev;
 struct dlist* next;
}dl;

dl* create(dl*);
void display(dl*);
void display_o(dl*, dl*);

int main()
{
 int ch;
 dl* head=NULL;
 dl* tail=NULL;
 
 do
 {
  printf("\n1-Create\n2-Display\n3-Display without overlapping\n4-Exit\n\nEnter your choice: ");
  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1:
    tail=create(tail);
    if(head==NULL)
    head=tail;
    break;
   case 2:
    display(head);
    break;
   case 3:
    display_o(head,tail);
    break;
   case 4:
    return 0;
   default:
    printf("\nInvalid no.\n");
    break;
  }
 }while(ch!=4);
}


dl* create(dl* tail)
{
 int v;
 dl* p=(dl*)malloc(sizeof(dl));
 
 if(!p)
 printf("Memory allocation failed");
 
 else
 {
  printf("\nEnter a value: ");
  scanf("%d",&v);
 
  p->data=v;
 
  if(tail!=NULL)
  tail->next=p;
 
  p->prev=tail;
  p->next=NULL;
 
  tail=p;
 }
 
 return tail;
}


void display(dl* head)
{
 if(head==NULL)
 {
  printf("\nList is empty\n");
  return;
 }
 
 while(head!=NULL)
 {
  printf("\nValue: %d",head->data);
  head=head->next;
 }
 printf("\n");
}


void display_o(dl* head, dl* tail)
{
 if(head==NULL)
 {
  printf("\nList is empty\n");
  return;
 }
 
 int h=0,t=1;
 do
 {
  if(h<t)
  {
   printf("\nValue: %d",head->data);
   
   if(head==tail)
   break;
   
   head=head->next;
   h++;
  }
  
  if(t>=h)
  {
   printf("\nValue: %d",tail->data);
   
   if(head==tail)
   break;
   
   tail=tail->prev;
   t++;
  }
 }while(1);
 printf("\n");
}






















