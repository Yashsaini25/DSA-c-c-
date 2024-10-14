#include <stdio.h>
#include <stdlib.h>

void enqueue(int[], int*, int*, int);
void dequeue(int[], int*, int*, int);
void display(int[], int, int, int);
void reverse_display(int[], int, int, int);

int main()
{
    int n,ch,f=-1,r=-1;
    printf("\nEnter the size of the circular queue: ");
    scanf("%d",&n);

    int* cqueue=(int*)malloc(n*sizeof(int));
    if(cqueue==NULL)
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
                enqueue(cqueue,&f,&r,n);
                break;
            case 2:
                dequeue(cqueue,&f,&r,n);
                break;
            case 3:
                display(cqueue,f,r,n);
                break;
            case 4:
                reverse_display(cqueue,f,r,n);
                break;
            case 5:
                free(cqueue);
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=5);
}


void enqueue(int cqueue[], int*f, int *r, int n)
{
    if(*f==(*r+1)%n)
    {
        printf("\nQueue is overflow\n");
        return;
    }

    int v;
    printf("\nEnter a value to be enqueued: ");
    scanf("%d",&v);

    if(*f==-1)
    *f=0;

    *r=(*r+1)%n;
    cqueue[*r]=v;
}


void dequeue(int cqueue[], int *f, int *r, int n)
{
    if(*f==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nValue dequeued: %d\n",cqueue[*f]);
    
    if(*f==*r)
    *f=*r=-1;
    else *f=(*f+1)%n;
}


void display(int cqueue[], int f, int r, int n)
{
    if(f==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    
    while(f!=r)
    {
        printf("\nvalue: %d",cqueue[f]);
        f=(f+1)%n;
    }
    printf("\nvalue: %d",cqueue[f]);
    printf("\n");
}


void reverse_display(int cqueue[], int f, int r, int n)
{
    if(r==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    while(r!=f)
    {
        printf("\nValue: %d",cqueue[r]);
        r=(r-1+n)%n;
    }
    printf("\nValue: %d",cqueue[r]);
    printf("\n");
}