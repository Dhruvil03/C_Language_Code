                          //CIRCULAR QUEUE USING ARRAY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
int que[N];
int front=(-1);
int rear=(-1);

void en_queue(int a)
{
    if(front==(-1) && rear==(-1))
    {
        front=rear=0;
        que[rear]=a;
    }
    else if(((rear+1)%N)==front)
    {
        printf("Queue is full.\n");
    }
    else
    {
          rear=(rear+1)%N;
          que[rear]=a;
    }
}

void de_queue()
{
    if(front==(-1)&& rear==(-1))
    printf("Queue is empty.\n");

    else if(front==rear)
    { 
        printf("Dequeued value = %d",que[front]);
        front=rear=(-1);
    }
    else
    {   
        printf("Dequeued value = %d",que[front]);
        front=(front+1)%N;
    }
}

void display()
{
    if(front==(-1) && rear==(-1))
    printf("Queue is empty.\n");

    else{
        int i=front;
        printf("Queue: ");
        while(i!=rear)
        {
            printf("%d-> ",que[i]);
            i=(i+1)%N;
        }
        printf("%d",que[i]);
        printf("\n");
    }
}

int main()
{
    int n,choice;
    
    while(1)
    {   printf("\n");
        printf("1.Insert a number\n");
        printf("2.Delete a number\n");
        printf("3.Diplay the queue\n");
        printf("4.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the value: ");
                   scanf("%d",&n);
                   en_queue(n);
                   break;
            case 2:de_queue();  
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default: printf("Invalid choice\n");   
                    break;  
        }
    }
    return 0;
}