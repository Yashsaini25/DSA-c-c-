#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* prev;
    struct list* next;
}dl;

void create(dl**, dl**);
void node_count(dl*);
void display(dl*);
void display_reverse(dl*);
void delete_first_node(dl**);
void delete_last_node(dl**);
void delete_at_nth_position(dl*, int);
void free_list(dl**);

int main()
{
    int ch,n,c=0;
    dl* head=NULL;
    dl* tail=NULL;

    do
    {
        printf("\n1-Create\n2-Node count\n3-Display\n4-Display reverse\n5-Delete at beginning\n6-Delete at end\n7-Delete at nth position\n8-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                create(&head, &tail);
                c++;
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
                delete_first_node(&head);
                if(head==NULL)
                tail=NULL;
                if(c>0)
                c--;
                break;
            case 6:
                delete_last_node(&tail);
                if(tail==NULL)
                head=NULL;
                if(c>0)
                c--;
                break;
            case 7:
                printf("\nWrite the node position: ");
                scanf("%d",&n);
                if(n==1)
                delete_first_node(&head);
                else if(n==c)
                delete_last_node(&tail);
                else if(n<=c && n>1)
                delete_at_nth_position(head, n);
                else if(n<1)
                {
                    printf("\nPosition should be greater than 0.\n");
                    break;
                }
                else 
                {
                    printf("\nNot enough nodes! Write a smaller no.\n");
                    break;
                }
                if(c>0)
                c--;
                break;
            case 8:
                free_list(&head);
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=8);
    
return 0;
}


void create(dl **head, dl** tail)
{
    int v;
    printf("\nEnter a value: ");
    scanf("%d",&v);
    
    dl* new_node=(dl*)malloc(sizeof(dl));

    if(!new_node)
    {
        printf("\nMemory allocation failed.\n");
        return;
    }

    new_node->data=v;
    new_node->prev=*tail;
    new_node->next=NULL;

    if(*head==NULL)
    *head=new_node;

    else (*tail)->next=new_node;
    
    *tail=new_node;
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


void delete_first_node(dl **head)
{
    if(*head==NULL)
    printf("\nList is empty\n");

    else
    {
        dl* p=*head;
        *head=(*head)->next;

        if(*head!=NULL)
        (*head)->prev=NULL;
        
        free(p);
    } 
}


void delete_last_node(dl **tail)
{
    if(*tail==NULL)
    printf("\nList is empty\n");

    else
    {
        dl* p=*tail;
        *tail=(*tail)->prev;

        if(*tail!=NULL)
        (*tail)->next=NULL;

        free(p);
    } 
}


void delete_at_nth_position(dl *head, int n)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        int c=2;

        while(c!=n)
        {
            head=head->next;
            c++;
        }

        dl* p=head->next;

        head->next=head->next->next;
        head->next->prev=head;

        free(p);
    }
}


void free_list(dl** head)
{
    while(*head!=NULL)
    {
        dl* p=*head;
        *head=(*head)->next;
        free(p);
    }
    *head=NULL;
}