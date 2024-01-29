#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#define size 5

int stack[25];
int top=-1;

void push();
void pop();
void display();

int main()
{
    int a,c,x,i=1;
    char b;
       printf("\n");
       do{
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nSelect your choice:");
        
        scanf("%d",&a);
        switch(a)
        {          
            case 1:push();
            break;

            case 2:pop();
            break;

            case 3:display();
            break;

            case 4:exit(0);
            break;
        }
        printf("\nYou want to continue?(Y/N)\n");
        b=getche();
       }
       while (b=='Y');
       getch();
    return 0;
    
}

void push()
{   
    top=top+1;
    if(top>=(size-1))
    printf("Overflow");
    else{
    printf("\nEnter the value to be push:");
    scanf("%d",&stack[top]);
    }
}

void pop()
{   
    if(top==(-1))
    printf("\nUnderflow\n");
    else
    {
        printf("\nPop value is %d\n",stack[top]);
    }
    top=top-1;
}


void display()
{   int i;
    if(top==(-1))
    {
        printf("\nstack is empty\n");
    }
    else{
        printf("\nStack elements are:");
        for(i=0;i<=top;i++){
        printf(" %d ",stack[i]);
        if(i<top)
        printf("-->");
        }
    }
}