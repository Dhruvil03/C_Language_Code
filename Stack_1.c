#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
int st[10];
int sp = -1;
int n = 10;
void push(int);
int pop();
void display();
void main()
{
 clock_t s, e;
 int ch, v;
 while (1)
 {
 s = clock();
 printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
 printf("\n Enter Choice: ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 printf("\nEnter Value: ");
 scanf("%d", &v);
 push(v);
 break;
 case 2:
 printf("\nPoped Element: ");
 v = pop();
 printf("%d\n", v);
 break;
 case 3:
 printf("\nContent of the stack :\n");
 display();
 break;
 case 4:
 e = clock();
 printf("\nTime taken: %d ms", (e - s) /CLOCKS_PER_SEC);
 exit(0);
 default:
 printf("Enter valid input");
 break;
 }
 }
}

void push(int x)
{
 if (sp <= (n - 1))
 {
 sp++;
 st[sp] = x;
 }
else
 {
 printf("Stack OverFlow");
 }
}
int pop()
{
 if (sp == -1){
 printf("Stack UnderFlow");
 return -1;
}
 else{
 return (st[sp--]);
 }
}
void display()
{
    int i;
    for (i = sp; i >= 0; i--){
     printf("%d\n",st[i]);
  }
}