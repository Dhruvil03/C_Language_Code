              //DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert_end(int a)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    printf("Linked list is empty\n");
    else{
        printf("\nLinked list: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void insert_beg(int a)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=head;
    temp->prev=NULL;
    if(head==NULL){
    head=tail=temp;
    }
    else
    {
        head=temp;
    }
    
}
void insert_after(int a,int b)
{
    struct node *p,*temp;
    p=head;

    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else{
    while(p->data!=a)
    {
         p=p->next;
    }
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=b;
        temp->prev=p;
        temp->next=p->next;
        p->next=temp;
    if(p->next==NULL){
        tail=temp;
    }
}
}
void reverse()
{
    struct node *p;
    p=tail;
    printf("\nLinked list in reverse: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
}

void sort(int a)
{
    struct node *pre,*post;
    int temp;
    pre=head;
    while(pre->next!=NULL)
    {
        post=pre->next;
        while(post!=NULL)
        {
            if(a==1)
            {    
                if(pre->data > post->data){
                 temp=pre->data;
                 pre->data=post->data;
                 post->data=temp;
                }
            }
            else{
                if(pre->data < post->data){
                temp=pre->data;
                pre->data=post->data;
                post->data=temp;
                }
            }
            post=post->next;
        }
        pre=pre->next;
    }
}
void delete(int a)
{   
    int flag=0;
    struct node *p,*temp;
    p=head;
    if(head==NULL)
    {
        printf("\nLink list is empty\n");
    }
    else{
    while(p->data!=a && p->next!=NULL)
    {
        p=p->next;
    }
    if(p->data==a)
    {
        temp=p->prev;
        temp->next=p->next;
        free(p);
        flag=1;
    }
    else if(flag==1)
    printf("\n%d is sucessfully deleted\n",a);
    else if(flag==0){
        printf("\n%d is not found\n",a);
    }
    }
}

void insert_before(int a,int b)
{
    struct node *temp,*p;
    p=head;
    
    while (p!=NULL)
    {
        /* code */
         if(p->data==a){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=b;
        temp->prev=p->prev;
        temp->next=p;
        p->prev=temp;
        temp->prev->next=temp;
        if (temp->prev==NULL)
        {
            head=temp;
        }
        break;
    }
    else
    {
        printf("%d is not found\n",a);
    }
        p=p->next;
    }
   /* if(p->data==a){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=b;
        temp->prev=p->prev;
        temp->next=p;
        p->prev=temp;
        if (temp->prev==NULL)
        {
            head=temp;
        }
    }
    else
    {
        printf("%d is not found\n",a);
    }*/
    
}
int main()
{
    //struct node *head=NULL;
    int choice,d,a,b;
    char ans;


     do{// printf("/n%p",head);
    printf("\n\n");
    printf("1.Insert a number at begining.\n");
    printf("2.Insert a number at end\n");
    printf("3.Insert after a number\n");
    printf("4.Insert before a number\n");
    printf("5.Sort in ascending order\n");
    printf("6.Sort in descending order\n");
    printf("7.Reverse the Linked list\n");
    printf("8.Display\n");
    printf("9.Delete\n");
    printf("10.Exit\n");
   // printf("5.Count the number of elements\n");
    printf("\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:printf("\nEnter a number you want to insert: ");
           scanf("%d",&d);
           insert_beg(d);
           break;
    case 2:printf("\nEnter a number you want to insert: ");
           scanf("%d",&d);
           insert_end(d);
           break;
    case 3:printf("\nEnter the number after which you want to enter a new number: ");
           scanf("%d",&a);
           printf("\nEnter a number you want to insert:");
           scanf("%d",&d);
           insert_after(a,d);
           break;
    case 4:printf("\nEnter the number before which you want to enter a new number: ");
           scanf("%d",&a);
           printf("\nEnter a number you want to insert:");
           scanf("%d",&d);
           insert_before(a,d);
           break;  
    case 5: sort(1);
            break;
    case 6: sort(2);
            break;
    case 7: reverse();
            break;      
    case 8:display();
           break;
    case 9: printf("\nEnter a number you want to delete: ");
            scanf("%d",&d);
            delete(d);
            break;
    case 10:exit(0);
           break;
    default:printf("\nInvalid input\n");
        break;
    }
     }
    while(1);

return 0;
}