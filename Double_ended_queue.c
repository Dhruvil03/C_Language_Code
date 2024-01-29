#include<stdio.h>
#include<stdlib.h>

#define N 5
int deque[N];
int f=(-1);
int r=(-1);

void en_que_front(int x)
{
    if((f==0 && r==N-1)||(f+1==r))
    {
        printf("\nQueue is full.");
    }
    else if(f==(-1) && r==(-1))
    {
        f=r=0;
        deque[f]=x;
    }
    else if(f==0)
    {
        f=N-1;
        deque[f]=x;
    }
    else{
        f--;
        deque[f]=x;
    }
}

void en_que_rare(int x)
{
    if((r==N-1 && f==0) || r-1==f)
    {
        printf("\nQueue is full.");
    }
    else if(f==(-1) && r==(-1))
    {
        r=f=0;
        deque[r]=x;
    }
    else if(r==(N-1))
    {
        r=0;
        deque[r]=x;
    }
    else{
        r++;
        deque[r]=x;
    }
}

void display()
{   
    int i;
    i=f;
    if(f==(-1) && r==(-1))
    {
        printf("\nQueue is empty");
    }
    else{
    printf("Queue: ");
    while(i!=r)
    {
        printf("%d ",deque[i]);
        i=(i+1)%N;
    }
    printf("%d ",deque[i]);
    }
}
void get_front()
{
    if(r==(-1) && f==(-1))
    {
        printf("\nQueue is empty");
    }
    else{
        printf("\nFront: %d",deque[f]);
    }
}

void get_rare()
{
    if(r==(-1) && f==(-1))
    {
        printf("\nQueue is empty");
    }
    else{
        printf("\nFront: %d",deque[r]);
    }
}

void de_queue_front()
{
    if(f==(-1) && r==(-1))
    {
         printf("\nQueue is empty");
    }
    else if(f==r)
    {   
        printf("\nDequed element : %d",deque[f]);
        r=f=(-1);
    }
    else{
          printf("\nDequed element : %d",deque[f]);
          f=(f+1)%N;
    }
}
void de_queue_rare()
{
    if(f==(-1) && r==(-1))
    {
         printf("\nQueue is empty");
    }
    else if(f==r)
    {   
        printf("\nDequed element : %d",deque[r]);
        r=f=(-1);
    }
    else if(r==0)
    {
         printf("\nDequed element : %d",deque[r]);
         r=N-1;
    }
    else{
          printf("\nDequed element : %d",deque[r]);
          r--;
    }
}

void main()
{
    int c,a;
    while(1)
    {
        printf("\n");
        printf("\n1.Enqueue front");
        printf("\n2.Enqueue rare");
        printf("\n3.Dequeue front");
        printf("\n4.Dequeue rare");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&c);
        switch (c)
        {
        case 1:printf("\nEnter the number:");
               scanf("%d",&a);
               en_que_front(a);
               break;
        case 2:printf("\nEnter the number:");
               scanf("%d",&a);
               en_que_rare(a);
               break;
        case 3:de_queue_front();
               break;
        case 4:de_queue_rare();
               break;
        case 5:display();
               break; 
        case 6:exit(0);
        break;      
        }
    }
}