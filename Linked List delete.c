#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}sl;

sl* insert(sl*);
sl* delete_1st_node(sl*);
void delete_2nd_node(sl*);
void delete_last_node(sl*);
void delete_2nd_last_node(sl*);
void delete_nth_node(sl*, int);
void node_count(sl*);
void display(sl*);

int main()
{
    int ch,c=0,n;
    sl* head=NULL;
    sl* tail=NULL;

    do
    {
        printf("\n1-Insertion\n2-Delete 1st node\n3-Delete 2nd node\n4-Delete last node\n5-Delete 2nd last node\n6-Delete nth node\n7-Node count\n8-Display\n9-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tail=insert(tail);
                if(head==NULL)
                head=tail;
                c++;
                break;
            case 2:
                head=delete_1st_node(head);
                if(c>0)
                c--;
                break;
            case 3:
                delete_2nd_node(head);
                if(c>1)
                c--;
                break;
            case 4:
                if(c==1)
                head=delete_1st_node(head);
                else delete_last_node(head);
                if(c>0)
                c--;
                break;
            case 5:
                if(c==2)
                head=delete_1st_node(head);
                else delete_2nd_last_node(head);
                if(c>1)
                c--;
                break;
            case 6:
                printf("\nEnter the node no.: ");
                scanf("%d",&n);
                if(n>c)
                {
                    printf("\nNot enough nodes. Write a smaller no.\n");
                    break;
                }
                else if(n==1)
                head=delete_1st_node(head);
                else delete_nth_node(head, n);
                if(c>0)
                c--;
                break;
            case 7:
                node_count(head);
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

sl* delete_1st_node(sl* head)
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

void delete_2nd_node(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        if(head->next!=NULL)
        {
            sl* p=head->next;
            head->next=head->next->next;
            free(p);
        }
        else printf("\nNot enough nodes!\n");
    }
}

void delete_last_node(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        while(head->next->next!=NULL)
        head=head->next;
        sl* p=head->next;
        head->next=head->next->next;
        free(p);
    }
}

void delete_2nd_last_node(sl* head)
{
    if(head==NULL)
    printf("\nList is empty\n");
    else
    {
        if(head->next!=NULL)
        {
            while(head->next->next->next!=NULL)
            head=head->next;
            sl* p=head->next;
            head->next=head->next->next;
            free(p);
        }
        else printf("\nNot enough nodes!\n");
    }
}

void delete_nth_node(sl* head, int n)
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
        sl* p=head->next;
        head->next=head->next->next;
        free(p);
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