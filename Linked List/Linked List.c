#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}sl;

sl* insert(sl** , sl*);
sl* deletion(sl*);
void display(sl*);
void alternate_display(sl*);
void node_count(sl*);
void even_node_count(sl*);
void odd_node_count(sl*);

int main()
{
    int ch;
    sl* head=NULL;
    sl* tail=NULL;

    do
    {
        printf("\n1-Insertion\n2-Deletion\n3-Display\n4-Alternate dislplay\n5-Node count\n6-Even>next count\n7-Odd>next count\n8-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tail=insert(&head,tail);
                break;
            case 2:
                head=deletion(head);
                if(head==NULL)
                tail=NULL;
                break;
            case 3:
                display(head);
                break;
            case 4:
                alternate_display(head);
                break;
            case 5:
                node_count(head);
                break;
            case 6:
                even_node_count(head);
                break;
            case 7:
                odd_node_count(head);
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=8);
    
return 0;
}

sl* insert(sl** head, sl *tail)
{
    int v;
    printf("\nEnter a value:");
    scanf("%d",&v);
    
    sl* new_node=(sl*)malloc(sizeof(sl));
    new_node->data=v;
    new_node->next=NULL;

    if(*head==NULL)
    {
        tail=new_node;
        *head=new_node;
    }

    else
    {
        tail->next=new_node;
        tail=new_node;
    }

    return tail;
}

sl* deletion(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        sl* p=head;
        head=head->next;
        free(p);
    }
    return head;
}

void display(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        while(head!=NULL)
        {
            printf("Value: %d\n",head->data);
            head=head->next;
        }
    }
}

void alternate_display(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while(head!=NULL)
        {
            printf("\nValue: %d",head->data);
            head=head->next;
            if(head==NULL)
            break;
            head=head->next;
        }
    } 
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
            c++;
            head=head->next;
        }
        printf("\nNo. of nodes: %d\n",c);
    }
}

void even_node_count(sl* head)
{
    int c=0;
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while(head!=NULL)
        {
            if(head->data%2==0)
            c++;
            head=head->next;
        }
        printf("\nNo. of even nodes: %d\n",c);
    }
}

void odd_node_count(sl* head)
{
    int c=0;
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while(head!=NULL)
        {
            if(head->data%2!=0)
            c++;
            head=head->next;
        }
        printf("\nNo. of odd nodes: %d\n",c);
    }
}
