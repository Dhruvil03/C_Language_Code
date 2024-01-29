#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int lb,int mid,int ub)
{   
    int b[100];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++){
       a[k]=b[k];
    }
}
void mergesort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int binary_search(int a[],int n,int data)
{   
    int l,r,mid;
    l=0;
    r=n;
    
    while(l<r)
    {
    mid=(l+r)/2;

    if(data==a[mid])
    return mid;

    else if(data>a[mid])
    l=mid+1;

    else
    {
        r=mid-1;
    }
    }
    if(l>r)
    return -1;
}
void print(int a[],int n)
{   
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
int main()
{
    int n,a,b;
    int arr[100];
    printf("\nTotal number of elements:");
    scanf("%d",&n);

    printf("\nEnter the element:");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   

    printf("\nGiven array:");
    print(arr,n);
    printf("\n");
    mergesort(arr,0,n-1);
    
    printf("\nSorted array:");
    print(arr,n);
    
    printf("\nEnter the element you want to search:");
    scanf("%d",&b);
    a=binary_search(arr,n-1,b);
    printf("%d is present at %d",b,a);

    return 0;
}