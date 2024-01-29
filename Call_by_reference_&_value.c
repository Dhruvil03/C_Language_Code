//Practical 1 : Intoduction to Pointers. Call by Value and
//Call by Reference.
#include <stdio.h>
#include <time.h>
//call by value
int sum(int a, int b)//declaring and defining function
{
 a = a++; //post incrementing the value of a
 b = --b; //pre decrementing the value of b
 
 printf("\nValue of n1 is %d.",a);
 printf("\nValue of n2 is %d.",b);
 
 int c=a+b;
 printf("\n%d + %d = %d", a,b,c);
 return c;
}
int main()
{
 int n1,n2;//declaring variables
 time_t t;
 time(&t);
 printf("Aim : Call by value");
 printf("\nTime and Date : %s",ctime(&t));
 printf("\n200130107112-CE-B2-CHAUHAN DHRUVILSINH AJAYSINH");
 printf("\n\nEnter the value of n1 : ");//entering the value of n1
 scanf("%d",&n1);
 printf("\nEnter the value of n2 : ");//entering the value of n2
 scanf("%d",&n2);
 int n3 = sum(n1, n2);//calling function
 
 return 0; }