#include <stdio.h>
#include <stdlib.h>

void push(int[], int*, int);
void pop(int[], int*);
void reverse_stack(int[], int);
void display(int[], int);
void reverse_display(int[], int);
void peek(int[], int);

int main()
{
    int n,top=-1,ch;

    printf("\nEnter the size of your stack: ");
    scanf("%d",&n);

    int *stack=(int*)malloc(n*sizeof(int));
    if(stack==NULL)
    {
        printf("\nMemory allocation failed\n");
        return -1;
    }

    do
    {
        printf("\n1-Push\n2-Pop\n3-Reverse stack\n4-Display\n5-Display in reverse\n6-Peek\n7-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push(stack,&top,n);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                reverse_stack(stack,top);
                break;
            case 4:
                display(stack,top);
                break;
            case 5:
                reverse_display(stack,top);
                break;
            case 6:
                peek(stack,top);
                break;
            case 7:
                free(stack);
                return 0;
            default:
                printf("\nInvalid choioce\n");
        }
    }while(ch!=7);
}


void push(int stack[], int* top, int n)
{
    if(*top==n-1)
    {
        printf("\nStack is overflow\n");
        return;
    }

    int v;
    printf("\nEnter a value to be pushed: ");
    scanf("%d",&v);
    (*top)++;
    stack[*top]=v;
}


void pop(int stack[], int* top)
{
    if(*top==-1)
    {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nValue poped: %d\n",stack[*top]);
    (*top)--;
}


void reverse_stack(int stack[], int top)
{
    if(top==-1)
    {
        printf("\nStack is empty\n");
        return;
    }

    int temp,j=top;
    for(int i=0;i<=top/2;i++,j--)
    {
        temp=stack[j];
        stack[j]=stack[i];
        stack[i]=temp;
    }
}


void display(int stack[], int top)
{
    if(top==-1)
    printf("\nStack is empty\n");

    else
    {
        while(top!=-1)
        {
            printf("\nValue: %d",stack[top]);
            top--;
        }
        printf("\n");
    }
}


void reverse_display(int stack[], int top)
{
    if(top==-1)
    printf("\nStack is empty\n");

    else
    {
        int temp=top;
        while(temp!=0)
        temp--;
        while(temp<=top)
        {
            printf("\nValue: %d",stack[temp]);
            temp++;
        }
        printf("\n");
    }
}


void peek(int stack[], int top)
{
    if(top==-1)
    printf("\nStack is empty\n");

    else printf("\nValue: %d\n",stack[top]);
}
