#include <stdio.h>
#include <stdlib.h>

typedef struct clist
{
    int time;
    struct clist* next;
}cl;

cl* create(cl*, cl*, int);
void cal_time(cl*, int);
cl* free_list(cl*);

int main()
{
    int ch,c=0;
    cl* head=NULL;
    cl* tail=NULL;

    do
    {
        printf("\n1-Create\n2-Calculate processing time\n3-Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tail=create(head, tail, c);
                c++;
                if(head==NULL)
                head=tail;
                break;
            case 2:
                cal_time(head, c);
                break;
            case 3:
                head=free_list(head);
                tail=NULL;
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=3);
    
return 0;
}


cl* create(cl *head, cl* tail, int c)
{
    int t;
    printf("\nEnter the processing time for task %d: ",c+1);
    scanf("%d",&t);
    
    cl* new_node=(cl*)malloc(sizeof(cl));
    new_node->next=NULL;

    if(!new_node)
    {
        printf("\nMemory allocation failed.\n");
        return tail;
    }

    new_node->time=t;

    if(head==NULL)
    head=new_node;

    else tail->next=new_node;
    
    tail=new_node;
    tail->next=head;

    return tail;
}


void cal_time(cl* head, int c)
{
    if(head==NULL)
    printf("\nList is empty\n");

    else
    {
        int t=10,n=0,i=0;
        do
        {
            while(n!=c)
            {
                if(head->time <= 10 && head->time>0)
                {
                    printf("\nTime taken for task %d is %d seconds: ",n+1,t);
                    i++;
                }
                head->time-=10;
                head=head->next;
                n++;
            }
            n=0;
            t+=10;
        }while(i!=c);
        printf("\n");
    }
}


cl* free_list(cl* head)
{
    if (head == NULL) 
    return NULL;
    
    cl* temp = head;
    cl* next_node = NULL;
    
    while (temp->next != head) 
    temp = temp->next;
    
    temp->next = NULL;  

    while (head != NULL) 
    {
        next_node = head->next;
        free(head);
        head = next_node;
    }
    return NULL;
}
