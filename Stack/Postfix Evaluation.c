#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 20

void push(int[], int, int*);
int pop(int[], int *);


int main()
{
    int l,top=-1,i=0,ans=0,ch,y,x,stack[max]; 
    char postfix[max];

    printf("Write the postfix expression: ");
    fgets(postfix,max,stdin);

    l=strlen(postfix);
    postfix[l-1]='\0';

    while(postfix[i]!='\0')
    {
        ch=postfix[i];

        if(ch>=48 && ch<=57)
        push(stack,ch-'0',&top);

        else
        {
            x=pop(stack,&top);
            y=pop(stack,&top);

            switch (ch)
            {
                case '+':
                    ans = y + x;
                    break;
                case '-':
                    ans = y - x;
                    break;
                case '*':
                    ans = y * x;
                    break;
                case '/':
                    ans = y / x;
                    break;
                case '^':
                    ans = pow(y , x);
                    break;
                case '%':
                    ans = y % x;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
            
            push(stack,ans,&top);
        }

        i++;
    }

    printf("%d\n",pop(stack,&top));
    return 0;

}


void push(int stack[], int ch, int *top)
{
    (*top)++;
    stack[*top]=ch;
}


int pop(int stack[],int *top)
{
    int ch=stack[*top];
    (*top)--;
    return ch;
}


