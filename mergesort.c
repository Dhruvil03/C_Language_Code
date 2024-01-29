#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int ,int ,int);

void mergesort(int arr[],int lb,int ub)
{   
    int mid;
    if(lb < ub)
    {   
        mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb,int mid,int ub)
{   
    int b[100];
    int i=lb;
    int j=mid+1;
    int k=lb;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
              b[k]=arr[i];
              i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++){
    arr[k]=b[k];
    }
}

void print(int arr[],int lb,int ub)
{
    for(int i=0;i<ub;i++)
    printf("%d ",arr[i]);
}

int main()
{
    int n;
    int arr[100];
    printf("\nTotal number of elements:");
    scanf("%d",&n);

    printf("\nEnter the element:");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   

    printf("\nGiven array:");
    print(arr,0,n);
    printf("\n");
    mergesort(arr,0,n-1);
    
    printf("\nSorted array:");
    print(arr,0,n);

    return 0;
}