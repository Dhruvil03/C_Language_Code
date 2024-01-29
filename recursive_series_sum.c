/*Series F(x)=x-x^3/3!+x^5/5!-...+x^n/n!*/
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

float p(int x,int n)
{
    int i;
    float power=1;
    for(i=1;i<=n;i++)
    {
        power=x*power;
    }
    return power;
}

float add(int x,int n)
{  
    int i;
    float add=0.0;
   for(i=1;i<=n;i+=4)
   {
      add=add+(p(x,i)/(float)fac(i));
   }
   return add;
}
float sub(int x,int n)
{  
    int i;
    double sub=0;
   for(i=3;i<=n;i+=4)
   {
      sub=(p(x,i)/(float)fac(i))+sub;
   }
   return sub;
}  

int main()
{
    int x,n;
    float ans;
    printf("For F(x)=x-x^3/3!+x^5/5!-...+x^n/n!\n");
    printf("\nEnter the value of x: ");
    scanf("%d",&x);
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    
    ans=add(x,n)-sub(x,n);

    printf("Answer of series is %f",ans);

    return 0;
}