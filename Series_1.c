/*For series 1+1/2!+1/3!+1/4!+.....+1/n!.*/
#include<stdio.h>

long fac(int x)
{
  int i;
  long mul=1;
  for(i=1;i<=x;i++)
  {
      mul=i*mul;
  }
  return mul;
}

int main()
{
    int n,i;
    float add=0.0;
    printf("For series 1+1/2!+1/3!+1/4!+.....+1/n!.\n");
    printf("\nEnter the value of n:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        add=add+1/(float)fac(i);
    } 

    printf("Answer of the series is %f",add);
    return 0;
}