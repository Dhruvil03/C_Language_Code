#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

char stack[10];
int top=-1;

void push(char a)
{
    top+=1;
    stack[top]=a;
}

char pop()
{
   char i;
   i=stack[top];
   top-=1;
   return i;
}

int prio(char x)
{
    if(x==')' || x=='(')
    return 1;
    
    else if(x=='-' || x=='+')
    return 2;

    else if(x=='*' || x=='/' )
    return 3;

    else
    return 4; 
}

int main()
{    
     int i=0,j=0;
	 char infix[100],b[2]={"(\0"},item,x,prefix[100];

     printf("Enter the infix expression:");
	 gets(infix);
     strcat(infix,")");
     strcat(b,infix);

     strrev(b);
     
     item=b[i];
     
     while(item!='\0')
     {
         if(item==')')
         push(item);

         else if(item=='(')
         {  
            x=pop();
            while(x!=')')
            {
                prefix[j]=x;
                j++;
                x=pop();
            }
         }
         else if(isalpha(item)||isdigit(item))
         {
             prefix[j]=item;
             j++;
         }
        else
        {
            x=pop();
            while(prio(item)<=prio(x))
            {
                prefix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        i++;
        item=b[i];
     }

    printf("\nPrefix expression:");

    for(int a=j-1;a>=0;a--)
    printf("%c",prefix[a]);

    return 0;
}