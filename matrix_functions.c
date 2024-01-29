#include <stdio.h>

int main()
{
  int a[100][100],b[100][100],c[100][100],d[100][100],p,q,i,j,m,n,k,sum,max,min;
  printf("Enter the number of rows and column for 1st matrix\n");
  scanf("%d%d",&p,&q);
  
  printf("Enter elements of 1st matrix\n");
  for(i=0;i<p;i++){
    for(j=0;j<q;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }

   printf("Enter the number of rows and column for 2st matrix\n");
   scanf("%d%d",&m,&n);

   printf("Enter elements of 2nd matrix\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++)
    {
      scanf("%d",&b[i][j]);
    }
  }

  if(p==m && q==n)
  {
  for(i=0;i<p;i++){
    for(j=0;j<q;j++)
    {
      c[i][j]=a[i][j]+b[i][j];
    }
  }
  }
  
   
  if(q==m)
  {
    for(i=0;i<p;i++)
    {
      for(j=0;j<n;j++)
      { sum=0;
        for(k=0;k<m;k++)
        {
           sum=sum + a[i][k]*b[k][j];
        }
        d[i][j]=sum;
      }
    }
  }
   

    if(p==m && q==n){
    printf("Addition of two matrix\n");
  for(i=0;i<p;i++){
    for(j=0;j<q;j++){
      printf("%d ",c[i][j]);
    }
      printf("\n");
   }
    }

  else
  printf("Invalid order for addition\n");

  if(q==m){
  printf("Multiplication of two matrix\n");
  for(i=0;i<p;i++)
    {
      for(j=0;j<n;j++)
      {
        printf("%d ",d[i][j]);
        }
        printf("\n");
    }
  }
   
   else
  printf("Invalid order for multiplication\n");
  
  max=a[0][0];
  min=a[0][0];
  for(i=0;i<p;i++)
  {
    for(j=0;j<q;j++)
    {
      if(a[i][j]>max)
      {
        max=a[i][j];
      }
      else if(a[i][j]<min)
      {
        min=a[i][j];
      }
    }
  }
  printf("The smallest and largest number of 1st matrix is %d and %d\n",min,max);

  max=b[0][0];
  min=b[0][0];
  for(i=0;i<p;i++)
  {
    for(j=0;j<q;j++)
    {
      if(b[i][j]>max)
      {
        max=b[i][j];
      }
      else if(b[i][j]<min)
      {
        min=b[i][j];
      }
    }
  }
   printf("The smallest and largest number of 1st matrix is %d and %d\n",min,max);
   return 0;
}
