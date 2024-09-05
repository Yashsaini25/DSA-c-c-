#include <stdio.h>
#include <stdlib.h>

typedef struct polynomail
{
 int coef;
 int exp;
 struct polynomail* next;
}py;

void create_poly(py**, py**);
void add_poly(py*, py*, py**);
void display(py*);

int main()
{
  int ch;
  py* head1=NULL;
  py* head2=NULL;
  py* head3=NULL;
  py* tail1=NULL;
  py* tail2=NULL;
  
  printf("\nWrite the expression for 1st polynomial\n");
  do
  {
   create_poly(&head1, &tail1);
   printf("\nDo you want to continue: ");
   scanf("%d",&ch);
  }while(ch!=0);
  
  printf("\nWrite the expression for 2nd polynomial\n");
  do
  {
   create_poly(&head2, &tail2);
   printf("\nDo you want to continue: ");
   scanf("%d",&ch);
  }while(ch!=0);
  
  add_poly(head2, head1, &head3);
  
  printf("\nPolynomail 1: ");
  display(head1);
  printf("\n\n");
  
  printf("Polynomail 2: ");
  display(head2);
  printf("\n\n");
  
  printf("Polynomail after adding: ");
  display(head3);
  printf("\n");
}


void create_poly(py** head, py** tail)
{
 int c,e;
 py* p=(py*)malloc(sizeof(py));
 
 printf("\nWrite the value of coefficeint: ");
 scanf("%d",&c);
 printf("Write the value of exponent: ");
 scanf("%d",&e);
 
 p->coef=c;
 p->exp=e;
 
 if(*head==NULL)
 {
  *head=p;
  *tail=p;
 }
 
 else (*tail)->next=p;
 
 p->next=NULL;
 *tail=p;
}


void add_poly(py* head2, py* head1, py** head)
{

 py* tail=NULL;
 
 while(head2!=NULL && head1!=NULL)
 {
  py* p=(py*)malloc(sizeof(py));
  
  if((head2->exp) == (head1->exp))
  {
   p->coef=head2->coef + head1->coef;
   p->exp=head2->exp;
  
   head2=head2->next;
   head1=head1->next;
  }
  
  else if((head2->exp) > (head1->exp))
  {
   p->coef=head2->coef;
   p->exp=head2->exp;
   head2=head2->next;
  }
  
  else if((head2->exp) < (head1->exp) )
  {
   p->coef=head1->coef;
   p->exp=head1->exp;
   head1=head1->next;
  }
  
  if(*head==NULL)
  {
   *head=p;
   tail=p;
  }
  
  else tail->next=p;
  
  p->next=NULL;
  tail=p;
  
 }
 
 while(head2!=NULL)
 {
  py* p=(py*)malloc(sizeof(py));
  
  p->coef=head2->coef;
  p->exp=head2->exp;
  
  head2=head2->next;

  tail->next=p;
  p->next=NULL;
  tail=p;
 }
  
 while(head1!=NULL)
 {
  py* p=(py*)malloc(sizeof(py));
  p->coef=head1->coef;
  p->exp=head1->exp;
  
  head1=head1->next;
  
  tail->next=p;
  p->next=NULL;
  tail=p;
 }
 
}


void display(py* head)
{
 if(head==NULL)
 printf("Expression not given");
 
 else
 {
  while(head!=NULL)
  {
   if(head->exp==0)
   printf("%d",head->coef);
   
   else if(head->exp==1)
   printf("%dx",head->coef);
   
   else printf("%dx^%d",head->coef,head->exp);
   
   if(head->next!=NULL)
   printf(" + ");
   
   head=head->next;
  }
 }
}
 
 
 
 


