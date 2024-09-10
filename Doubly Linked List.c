#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* prev;
    struct list* next;
}dl;

dl* create(dl*);
void node_count(dl*);
void display(dl*);
void display_reverse(dl*);

int main()
{
    int ch;
    dl* head=NULL;

    do
    {
        printf("\n1-Create\n2-Node count\n3-Display\n4-Display reverse\n5-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                head=create(head);
                break;
            case 2:
                node_count(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                display_reverse(head);
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=5);
    
return 0;
}


dl* create(dl *head)
{
    int v;
    printf("\nEnter a value: ");
    scanf("%d",&v);
    
    dl* new_node=(dl*)malloc(sizeof(dl));
    new_node->data=v;

    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL)
    return new_node;

    else
    {
        dl* temp=head;

        while(temp->next!=NULL)
        temp=temp->next;

        new_node->prev=temp;
        temp->next=new_node;

        return head;
    } 
}


void node_count(dl* head)
{
    int c=0;

    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        while(head!=NULL)
        {
            head=head->next;
            c++;
        }
        printf("\nNo. of nodes: %d\n",c);
    }
}


void display(dl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        while(head!=NULL)
        {
            printf("\nValue: %d",head->data);
            head=head->next;
        }
        printf("\n");
    }
}


void display_reverse(dl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        while(head->next!=NULL)
        head=head->next;

        while(head!=NULL)
        {
            printf("\nValue: %d",head->data);
            head=head->prev;
        }
        printf("\n");
    }
}
