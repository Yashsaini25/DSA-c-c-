#include <stdio.h>
#include <stdlib.h>

void enqueue(int[], int*, int*, int);
void dequeue(int[], int*, int*);
void display(int[], int, int);
void reverse_display(int[], int, int);

int main()
{
    int n,ch,f=-1,r=-1;
    printf("\nEnter the size of the queue: ");
    scanf("%d",&n);

    int* queue=(int*)malloc(n*sizeof(int));
    if(queue==NULL)
    {
        printf("\nMemory allocation failed\n");
        return -1;
    }

    do
    {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Display in reverse\n5-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue(queue,&f,&r,n);
                break;
            case 2:
                dequeue(queue,&f,&r);
                break;
            case 3:
                display(queue,f,r);
                break;
            case 4:
                reverse_display(queue,f,r);
                break;
            case 5:
                free(queue);
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=5);
}


void enqueue(int queue[], int*f, int *r, int n)
{
    if(*r==n-1)
    {
        printf("\nQueue is overflow\n");
        return;
    }

    int v;
    printf("\nEnter a value to be enqueued: ");
    scanf("%d",&v);

    if(*f==-1)
    *f=0;
    
    (*r)++;
    queue[*r]=v;
}


void dequeue(int queue[], int *f, int *r)
{
    if(*f==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nValue dequeued: %d\n",queue[*f]);
    if(*f==*r)
    *f=*r=-1;
    else (*f)++;
}


void display(int queue[], int f, int r)
{
    if(f==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    
    while(f<=r)
    {
        printf("\nvalue: %d",queue[f]);
        f++;
    }
    printf("\n");
}


void reverse_display(int queue[], int f, int r)
{
    if(r==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    while(r>=f)
    {
        printf("\nValue: %d",queue[r]);
        r--;
    }
    printf("\n");
}
