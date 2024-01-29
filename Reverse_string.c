#include<stdio.h>

int main()
{ 
  int len=0,j,m=-1,n=0;  
  char *i,a[100]; 
   
   i=&a[0];
  printf("\nEnter string:");
  gets(i);
  
  //puts(*i);

  while(a[n]!='\0')
  {
      len=len+1;
      n++;
  }
 
  i=&a[len-1];
  
  printf("\nString in reverse:");
  for(j=0;j<len;j++)
  {
      printf("%c",*i);
      i--;
  }
 
  return 0;
}