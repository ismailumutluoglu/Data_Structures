#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data ; 
    struct node*left ; 
    struct node*right ; 
};

struct node*createBST(int data);
struct node*insertBST(struct node*root,int data);
void inorder(struct node*root);

int main()
{
    struct node*root = NULL ; 

    root = insertBST(root,20);
    root = insertBST(root,10);
    root = insertBST(root,5);
    root = insertBST(root,11);
    root = insertBST(root,19);

    inorder(root);
    return 0 ; 
}

struct node*createBST(int data)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data ; 
    newnode->left = NULL ; 
    newnode->right = NULL ; 
    
    return newnode ; 
}

struct node*insertBST(struct node*root,int data)
{
    if(root == NULL)
        return createBST(data);
    else
    {
        if(data < root->data)
        {
            root->left = insertBST(root->left,data);
        }
        else if(data > root->data)
        {
            root->right = insertBST(root->right,data);
        }
    }
    return root ; 
}


void inorder(struct node*root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}