                //Circular Queue Using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
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

    if(rear==NULL && front==NULL)
    {
        rear=front=temp;
        rear->link=front;
    }
    else{
        rear->link=temp;
        rear=temp;
        temp->link=front;
    }
}

void display()
{
    struct node *temp;
    temp=front;

    if(front==NULL && rear==NULL)
    printf("Queue is empty\n");

    else{ 
    printf("Queue: ");    
    do
    {   
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    while(temp!=front);
    }
}

void de_queue()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    printf("Queue is empty.\n");
    else if(front==rear)
    {
        printf("Dequeued element: %d\n",front->data);
        rear=front=NULL;
        free(temp);
    }
    else {
        printf("Dequeued element: %d\n",front->data);
        front=front->link;
        rear->link=front;
        free(temp);
    }
}
int main()
{
     int choice,n;
    
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
    return 0;
}