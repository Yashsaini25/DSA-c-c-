#include <stdio.h>
#include <string.h>
#define max 20

void push(char[], char, int*);
int pop(char[], int *);
int pcd(char);

int main()
{
    int l,top=-1,i=0,j=0;
    char infix[max],stack[max],postfix[max],ch,x;

    printf("Write the infix expression: ");
    fgets(infix,max,stdin);

    l=strlen(infix);
    infix[l-1]=')';

    push(stack,'(',&top);

    while(infix[i]!='\0')
    {
        ch=infix[i];

        if(ch=='(')
        push(stack,ch,&top);

        else if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        {
            postfix[j]=ch;
            j++;
        }

        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                x=pop(stack,&top);
                postfix[j]=x;
                j++;
            }
            
            pop(stack,&top);
        }

        else
        {
            while(pcd(ch)<=pcd(stack[top]))
            {
                x=pop(stack,&top);
                postfix[j]=x;
                j++;
            }

            push(stack,ch,&top);
        }

        i++;
    }

    postfix[i]='\0';

    printf("%s\n",postfix);
    return 0;

}


void push(char stack[], char ch, int *top)
{
    (*top)++;
    stack[*top]=ch;
}


int pop(char stack[],int *top)

{
    int x=stack[*top];
    (*top)--;
    return x;
}


int pcd(char ch)
{
    if(ch=='^')
    return 4;

    else if(ch=='*' || ch=='/' || ch=='%')
    return 3;

    else if(ch=='+' || ch=='-')
    return 2;

    else return 1;
}