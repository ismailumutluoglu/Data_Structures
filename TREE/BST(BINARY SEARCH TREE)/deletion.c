#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node*left ; 
    int data ; 
    struct node*right ; 
};

struct node*insert(struct node*root,int data);
struct node*search(struct node*root,int data);
struct node*deletion(struct node*root,int data);
struct node*findMin(struct node*root);
void inorder(struct node*root);

int main()
{
    struct node*root = NULL ; 

    root = insert(root,50);
    root = insert(root,45);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,10);
    
    inorder(root);

    struct node*check = search(root,10) ; 
    if(check != NULL)
        printf("var\n");
    else
        printf("yok");

    deletion(root,30);

    inorder(root);

    return 0 ; 
}

struct node*create(struct node*create,int data)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = NULL ; 
    newnode->data = data ; 
    newnode->right = NULL ;
    return newnode ;  
}

struct node*findMin(struct node*root)
{
    struct node*temp = root ; 
    while(temp != NULL && temp->left != NULL)
    {
        temp = temp->left ; 
    }
    return temp ; 
}


struct node*insert(struct node*root,int data)
{
    if(root == NULL)
    {
        return create(root,data);
    }
    else
    {
        if(data < root->data)
            root->left = insert(root->left,data);
        else if(data > root->data)
            root->right = insert(root->right,data);
    }
    return root ; 
}

struct node*search(struct node*root,int data)
{
    if(root == NULL)
        return NULL ;
    else
    {
        if(root->data == data)
            return root ; 
        else if(data < root->data)
            root->left = search(root->left,data);
        else
            root->right = search(root->left,data);
    }
}

struct node*deletion(struct node*root,int data)
{
    if(root == NULL)
        return NULL ; 
    else
    {
        if(data < root->data)
            root->left = deletion(root->left,data);
        else if(data > root->data)
            root->right = deletion(root->right,data);
        else
        {
            //hiç çocuğu olmayan ; 
            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL ; 
            }
            // tek çocuğu olan ; 
            else if(root->left == NULL && root->right != NULL)
            {
                struct node*temp = root->right ; 
                free(root);
                return temp ; 
            }
            else if(root->left != NULL && root->right == NULL)
            {
                struct node*temp = root->left ; 
                free(root) ;
                return temp ; 
            }
            //iki çocuğu olan
            else
            {
                struct node*temp =  findMin(root->right) ;
                root->data = temp->data ;
                root->right = deletion(root->right,temp->data) ;
            }
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