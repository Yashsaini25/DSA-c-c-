#include <stdio.h>
#include <stdlib.h>

typedef struct dlist
{
 int data;
 struct dlist* prev;
 struct dlist* next;
}dl;

void create(dl**);
void display(dl*);

int main()
{
 int ch;
 dl* head=NULL;
 dl* tail=NULL;
 
 do
 {
  printf("\n1-Create\n2-Display\n3-Exit\n\nEnter your choice: ");
  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1:
    create(&head);
    break;
   case 2:
    display(head);
    break;
   case 3:
    return 0;
   default:
    printf("\nInvalid no.\n");
    break;
  }
 }while(ch!=3);
}


void create(dl** head)
{
 int v;

 printf("\nEnter a value: ");
 scanf("%d",&v);
 
 dl* p=(dl*)malloc(sizeof(dl));
 
 if(!p)
 {
  printf("Memory allocation failed");
  return;
 }
  
 p->data=v;
   
 if(*head==NULL) 
 {
  p->prev=NULL;
  p->next=NULL;
 
  *head=p;
 }
  
 else if(v < (*head)->data)
 {
  (*head)->prev=p;
  
  p->next=*head;
  p->prev=NULL;
  
  *head=p;
 }
  
 else
 {
  int c=0;
  dl* temp=*head;
  
  while(temp->next!=NULL)
  {
   if(v < temp->data)
   {
    p->next=temp;
    p->prev=temp->prev;
    
    temp->prev->next=p;
    temp->prev=p;
    
    c=1;
    break;
   }
   temp=temp->next;
  }
  
 if(c==0)
 {
  p->prev=temp;
  p->next=NULL;
   
  temp->next=p;
 }
 }
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
