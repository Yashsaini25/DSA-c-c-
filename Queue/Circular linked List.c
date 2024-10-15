#include <stdio.h>
#include <stdlib.h>

typedef struct circular_linked_list
{
    int data;
    struct circular_linked_list* next;
}cl;

void enqueue(cl**, cl**);
void dequeue(cl**, cl**);
void display(cl*, cl*);
void free_queue(cl**, cl**);

int main()
{
    int ch;
    cl *head=NULL, *tail=NULL;
    do
    {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue(&head,&tail);
                break;
            case 2:
                dequeue(&head,&tail);
                break;
            case 3:
                display(head,tail);
                break;
            case 4:
                free_queue(&head,&tail);
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=4);
}


void enqueue(cl** head, cl** tail)
{
    cl* p=(cl*)malloc(sizeof(cl));
    if(p==NULL)
    {
        printf("\nMemory allocation failed\n");
        return;
    }

    int v;
    printf("\nEnter a value to be enqueued: ");
    scanf("%d",&v);
    p->data=v;

    if(*head==NULL)
    *head=p;
    else (*tail)->next=p;

    *tail=p;
    (*tail)->next=*head;
}


void dequeue(cl** head, cl** tail)
{
    if(*head==NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    cl* temp=*head;

    printf("\nValue dequeued: %d\n",(*head)->data);

    if(*head==*tail)
    *head=*tail=NULL;

    else
    {
        *head=(*head)->next;
        (*tail)->next=*head;
    }

    free(temp);
}


void display(cl* head, cl* tail)
{
    if(head==NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    while(head!=tail)
    {
        printf("\nValue: %d",head->data);
        head=head->next;
    }
    printf("\nValue: %d\n",head->data);
}


void free_queue(cl** head, cl** tail)
{
    if(*head==NULL)
    return;

    cl* temp;
    while(*head!=*tail)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    free(*head);
    *head=*tail=NULL;
}