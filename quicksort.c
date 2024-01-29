#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

int partition( int a[],int lb, int ub)
{   
    int pivot,start,end,b,c;
    pivot=a[lb];
    start=lb;
    end=ub;
    while(start<end){
    while(a[start]<=pivot)
    {
        start++;
    }

    while(a[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(&a[start],&a[end]);
    }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void quicksort(int a[],int lb,int ub)
{   
    int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

void print(int a[],int n)
{   
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}

int main()
{
    int a[100],n;
    printf("\nTotal no of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nGiven Array:");
    print(a,n);
    quicksort(a,0,n-1);
    printf("\nSorted Array:");
    print(a,n);

    return 0;
}
