              //LINEAR QUEUE USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    /* data */
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void en_queue(int a)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->link=NULL;
    if(front==NULL && rear==NULL){
    front=rear=temp;
    }
    else
    {   
        rear->link=temp;
        rear=temp;
    }
    
}

void display()
{
    struct node *temp;
    temp=front;
    
    if(front==NULL && rear==NULL)
    printf("Queue is empty.\n");
    else{
    printf("\nQueue: ");
    while(temp!=NULL)
    {  
        printf("->%d",temp->data);
        temp=temp->link;
    }
    }
}

void de_queue()
{
    struct node *temp;
     temp=front;
    if(front==NULL && rear==NULL){
    printf("Queue is empty.\n");
    }
    else if(rear==front)
    {
        rear=front=NULL;
    }
    else
    { 
    printf("Dequeued element is %d",front->data);
    front=front->link;
    free(temp);
    }
    
}
void main()
{
    int choice,n;

       printf("\nDhruvilsinh .A. Chauhan\n");
       printf("Enroll no.- 200130107112\n");
       printf("CE-B2\n");
       printf("\n");
    
    while (1)
    {
        /* code */
         printf("\n");
        printf("1.Insert a number\n");
        printf("2.Delete a number\n");
        printf("3.Diplay the queue\n");
        printf("4.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        printf("\n");
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
    
}
