#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *create()
{
    struct node *newnode;
    newnode=(struct  node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the data (-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
    return 0;
    newnode->data=x;
    printf("Enter left child of %d",x);
    newnode->left=create();
    
    printf("Enter right child of %d",x);
    newnode->right=create();

    return newnode;
}

void preorder(struct node *root)
{    
    if(root==NULL)
    {
        return;
    }
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
}
void postorder(struct node *root)
{    
    if(root==NULL)
    {   
        return;
    }
     postorder(root->left);
     postorder(root->right);
     printf("%d ",root->data);
}
void inorder(struct node *root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{   
    int a;
    struct node *root;
    root=NULL;
    root=create();
    
    while (1)
    {
        /* code */
        printf("\n1.Inorder Traversal");
        printf("\n2.Preorder Traversal");
        printf("\n3.Postorder Traversal");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        
        switch (a)
        {
        case 1:
            printf("\n");
            printf("\nInorder Traversal:");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("\n");
            printf("\nPre-order Traversal:");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("\n");
            printf("\nPost-order Traversal:");
            postorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
