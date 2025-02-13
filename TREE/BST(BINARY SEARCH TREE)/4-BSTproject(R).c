//binary search tree rekursiv fonk kullanarak insert ve search örneği

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*left ; 
    int data ; 
    struct Node*right ; 
};

struct Node*Create(struct Node*root,int data);
struct Node*insertBST(struct Node*root,int data);
void inorderBST(struct Node*root);
struct Node*searchBST(struct Node*root,int data);

int main()
{
    //---------------------------
    struct Node*root = NULL ; 
    root = insertBST(root,10);
    insertBST(root,20);
    insertBST(root,15);
    insertBST(root,30);
    insertBST(root,40);
    insertBST(root,25);
    insertBST(root,26);
    insertBST(root,60);
    insertBST(root,50);
    insertBST(root,45);
    //---------------------------
    inorderBST(root);
    printf("\n");
    //---------------------------
    struct Node*check = searchBST(root,45);
    if(check == NULL)
        printf("aranan deger agacta yok");
    else
        printf("aranan deger agacta var");
    //---------------------------
    return 0 ; 
}


struct Node*Create(struct Node*root,int data)
{
    struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->left = NULL ; 
    newnode->data = data ; 
    newnode->right = NULL ; 
    return newnode ;
}

struct Node*insertBST(struct Node*root,int data)
{
    if(root == NULL)
    {
        return Create(root,data); 
    }

    else if(data < root->data)
        root->left = insertBST(root->left,data) ;
    else
        root->right = insertBST(root->right,data) ;    
    return root ; 
}

void inorderBST(struct Node*root)
{
    if(root != NULL)
    {
        inorderBST(root->left);
        printf("%d ",root->data);
        inorderBST(root->right);
    }
}

struct Node*searchBST(struct Node*root,int data)
{
    if(root == NULL)
        return NULL ; 
    else if(data == root->data)
        return root ; 
    else if(data < root->data)
        searchBST(root->left,data) ;
    else
        searchBST(root->right,data) ;
}

