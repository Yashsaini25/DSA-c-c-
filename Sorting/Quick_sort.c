#include <stdio.h>
#include <stdlib.h>

void quick_sort(int[], int, int);

int main()
{
    int n,i;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);

    int* a=(int*)malloc(n*sizeof(int));
    if(!a)
    {
        printf("\nMemory allocation failed");
        return 1;
    }

    printf("\nEnter array elements-\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    quick_sort(a,0,n-1);

    printf("\nSorted array-\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");

    free(a);
    return 0;
}


void quick_sort(int a[], int lb, int ub)
{
    if(lb>=ub)
    return;

    int key=a[lb], i=lb+1, j=ub, t;
    
    while(i<=j)
    {
        while(key >= a[i] && i<=ub)
        i++;

        while(key < a[j])
        j--;

        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[lb]=a[j];
    a[j]=key;
    quick_sort(a,lb,j-1);
    quick_sort(a,j+1,ub);
}