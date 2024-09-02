#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}sl;

sl* insert(sl**, sl*);
sl* insert_before_1st_node(sl*);
void insert_after_1st_node(sl*);
void insert_before_last_node(sl*,sl*);
sl* insert_after_last_node(sl*);
void insert_before_nth_node(sl*, int);
void insert_after_nth_node(sl*, int);
void display(sl*);

int main()
{
    int ch,c=0,n;
    sl* head=NULL;
    sl* tail=NULL;

    do
    {
        printf("\n1-Insertion\n2-Insert before 1st node\n3-Insert after 1st node\n4-Insert before last node\n5-Insert after last node\n6-Insert before nth node\n7-Insert after nth node\n8-Display\n9-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tail=insert(&head,tail);
                c++;
                break;
            case 2:
                head=insert_before_1st_node(head);
                c++;
                break;
            case 3:
                insert_after_1st_node(head);
                c++;
                break;
            case 4:
                insert_before_last_node(head,tail);
                c++;
                break;
            case 5:
                tail=insert_after_last_node(tail);
                c++;
                break;
            case 6:
                printf("Enter the node no.\n");
                scanf("%d",&n);
                if(n>c)
                {
                    printf("Not enough nodes. Write a smaller no.\n");
                    break;
                }
                else if(n==1)
                head=insert_before_1st_node(head);
                else if(n==c)
                insert_before_last_node(head, tail);
                else insert_before_nth_node(head, n);
                c++;
                break;
            case 7:
                printf("Enter the node no.\n");
                scanf("%d",&n);
                if(n>c)
                {
                    printf("Not enough nodes. Write a smaller no.\n");
                    break;
                }
                else if(n==c)
                tail=insert_after_last_node(tail);
                else insert_after_nth_node(head, n);
                c++;
                break;
            case 8:
                display(head);
                break;
            case 9:
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=9);
    
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

sl* insert_before_1st_node(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        int v;
        printf("\nEnter a value: ");
        scanf("%d",&v);
        sl* p=(sl*)malloc(sizeof(sl));
        p->data=v;
        p->next=head;
        head=p;
    }
    return head;
}

void insert_after_1st_node(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        int v;
        printf("\nEnter a value: ");
        scanf("%d",&v);
        sl* p=(sl*)malloc(sizeof(sl));
        p->data=v;
        p->next=head->next;
        head->next=p;
    }
}

void insert_before_last_node(sl* head,sl* tail)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        int v;
        printf("\nEnter a value: ");
        scanf("%d",&v);
        sl* p=(sl*)malloc(sizeof(sl));
        p->data=v;
        while(head->next!=tail)
        head=head->next;
        p->next=tail;
        head->next=p;
    }
}

sl* insert_after_last_node(sl* tail)
{
    if(tail==NULL)
    printf("\nList is empty\n");
    else
    {
        int v;
        printf("\nEnter a value: ");
        scanf("%d",&v);
        sl* p=(sl*)malloc(sizeof(sl));
        p->data=v;
        tail->next=p;
        tail=p;
        p->next=NULL;
    }
    return tail;
}


void insert_before_nth_node(sl* head, int n)
{
    int c=1;
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while((c+1)!=n)
        {
            head=head->next;
            c++;
        }
        sl* p=(sl*)malloc(sizeof(sl));
        printf("Enter a value: \n");
        scanf("%d",&c);
        p->data=c;
        p->next=head->next;
        head->next=p;
    }
}

void insert_after_nth_node(sl* head, int n)
{
    int c=1;
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while(c!=n)
        {
            head=head->next;
            c++;
        }
        sl* p=(sl*)malloc(sizeof(sl));
        printf("Enter a value: \n");
        scanf("%d",&c);
        p->data=c;
        p->next=head->next;
        head->next=p;
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