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
void insert_at_begn(dl**);
void insert_at_end(dl**);
void insert_at_nth_position(dl*, int);
void free_list(dl**);

int main()
{
    int ch,n,c=0;
    dl* head=NULL;
    dl* tail=NULL;

    do
    {
        printf("\n1-Create\n2-Node count\n3-Display\n4-Display reverse\n5-Insert at beginning\n6-Insert at end\n7-Insert at nth position\n8-Exit\n\nEnter your choice: ");
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
                insert_at_begn(&head);
                if(c>0)
                c++;
                break;
            case 6:
                insert_at_end(&tail);
                if(c>0)
                c++;
                break;
            case 7:
                printf("\nWrite the node position: ");
                scanf("%d",&n);
                if(n==1)
                insert_at_begn(&head);
                else if(n<=c && n>1)
                insert_at_nth_position(head, n);
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
                c++;
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


void insert_at_begn(dl **head)
{
    if(*head==NULL)
    printf("\nList is empty\n");

    else
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
        new_node->prev=NULL;
        new_node->next=*head;

        (*head)->prev=new_node;
        *head=new_node;   
    } 
}


void insert_at_end(dl **tail)
{
    if(*tail==NULL)
    printf("\nList is empty\n");

    else
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

        (*tail)->next=new_node;
        *tail=new_node;
    } 
}


void insert_at_nth_position(dl *head, int n)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        int v,c=2;
        printf("\nEnter a value: ");
        scanf("%d",&v);
    
        dl* new_node=(dl*)malloc(sizeof(dl));

        if(!new_node)
        {
            printf("\nMemory allocation failed.\n");
            return;
        }

        new_node->data=v;

        while(c!=n)
        {
            head=head->next;
            c++;
        }

        new_node->prev=head;
        new_node->next=head->next;

        head->next->prev=new_node;  
        head->next=new_node;
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
