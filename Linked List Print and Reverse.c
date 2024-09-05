#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}sl;

sl* insert(sl*);
void node_count(sl*);
void display(sl*);
void display_recursion(sl*);
void display_reverse_recursion(sl*);
sl* reverse(sl*);
sl* reverse_recursion(sl*);

int main()
{
    int ch;
    sl* head=NULL;
    sl* tail=NULL;

    do
    {
        printf("\n1-Insertion\n2-Node count\n3-Display\n4-Display using recursion\n5-Display reverse\n6-Reverse Linked list\n7-Reverse Linked list using recursion\n8-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tail=insert(tail);
                if(head==NULL)
                head=tail;
                break;
            case 2:
                node_count(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                if(head==NULL)
                printf("\nList is empty\n");
                else display_recursion(head);
                printf("\n");
                break;
            case 5:
                if(head==NULL)
                printf("\nList is empty\n");
                else display_reverse_recursion(head);
                printf("\n");
                break;
            case 6:
                head=reverse(head);
                break;
            case 7:
                if(head==NULL)
                printf("\nList is empty\n");
                else head=reverse_recursion(head);
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=8);
    
return 0;
}


sl* insert(sl *tail)
{
    int v;
    printf("\nEnter a value: ");
    scanf("%d",&v);
    
    sl* new_node=(sl*)malloc(sizeof(sl));
    new_node->data=v;
    new_node->next=NULL;

    if(tail!=NULL)
    tail->next=new_node;
    tail=new_node;

    return tail;
}


void node_count(sl* head)
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


void display(sl* head)
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


void display_recursion(sl* head)
{
    if(head==NULL)
    return;

    printf("\nValue: %d",head->data);
    display_recursion(head->next);
}


void display_reverse_recursion(sl* head)
{
    if(head==NULL)
    return;
    
    display_reverse_recursion(head->next);
    printf("\nValue: %d",head->data);
}


sl* reverse(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        sl *prev, *current, *next;
        current=head;
        prev=NULL;

        while(next!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    return head;
}


sl* reverse_recursion(sl* head)
{
    if(head->next==NULL)
    return head;

    sl* p=reverse_recursion(head->next);

    head->next->next=head;
    head->next=NULL;

    return p;
}