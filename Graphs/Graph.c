#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int value,weight;
    struct graph* next;
}gr;

void insert(gr**);

int main()
{
    int ch,n,c=0;
    printf("\nEnter the no. of vertices");
    scanf("%d",&n);
    gr* a[n];

    for(int i=0;i<n;i++)
    a[i]=NULL;

    do
    {
        printf("\n1-Create\n2-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(c<n)
                {
                    insert(&a[c]);
                    c++;
                }
                else printf("\nMaximum vertices reached\n");
                break;
            case 2:
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }while(ch!=2);
}


void insert(gr** a)
{
    int v,wt;

    while(1)
    {
        printf("\nEnter the value and weight to which the present node is conected\nEnter 0 if alreday connected\n");
        scanf("%d",&v);
        if(v==0)
        break;
        scanf("%d",&wt);

        gr *n=(gr*)malloc(sizeof(gr));
        if(n==NULL)
        {
            printf("\nMemory allocation failed\n");
            return;
        }

        n->value=v;
        n->weight=wt;
        n->next=NULL;
        
        if(*a==NULL)
        *a=n;

        else
        {
            gr* temp=*a;
            while(temp->next!=NULL)
            temp=temp->next;

            temp->next=n;
        }
    }
}


