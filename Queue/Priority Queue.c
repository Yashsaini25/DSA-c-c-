#include <stdio.h>
#include <stdlib.h>

void enqueue(int[], int*, int*, int);
void dequeue(int[], int*, int*);
void display(int[], int, int);

int main()
{
    int n,ch,f=-1,r=-1;
    printf("\nEnter the size of the priority queue: ");
    scanf("%d",&n);

    int* pqueue=(int*)malloc(2*n*sizeof(int));
    if(pqueue==NULL)
    {
        printf("\nMemory allocation failed\n");
        return -1;
    }

    do
    {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue(pqueue,&f,&r,n);
                break;
            case 2:
                dequeue(pqueue,&f,&r);
                break;
            case 3:
                display(pqueue,f,r);
                break;
            case 4:
                free(pqueue);
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=4);
}


void enqueue(int pqueue[], int*f, int *r, int n)
{
    if(*r==2*n-1)
    {
        printf("\nQueue is overflow\n");
        return;
    }

    int v,p;
    printf("\nEnter a value to be enqueued: ");
    scanf("%d",&v);
    printf("\nEnter the priority: ");
    scanf("%d",&p);

    if(*f==-1)
    *f=0;

    (*r)++;
    pqueue[*r]=v;
    (*r)++;
    pqueue[*r]=p;
}


void dequeue(int pqueue[], int *f, int* r)
{
    if(*r==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    int k=pqueue[1],ind=0;
    for(int i=1;i <= *r;i+=2)
    {
        if(k>=pqueue[i])
        {
            k=pqueue[i];
            ind=i;
        }
    }

    printf("\nValue dequeued: %d\nPriority: %d\n",pqueue[ind-1],pqueue[ind]);
    
    for(int i=ind-1;i<*r-1;i++)
    pqueue[i]=pqueue[i+2];

    *r-=2;
   
    if(*r < *f)
    *f=*r=-1;
}


void display(int pqueue[], int f, int r)
{
    if(r==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    for(int i=f;i<r;i+=2)
    printf("\nValue: %d\nPriority: %d\n",pqueue[i],pqueue[i+1]);
}
