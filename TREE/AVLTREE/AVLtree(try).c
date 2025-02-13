#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node*left ; 
    int data ; 
    struct Node*right ; 
    int height ; 
};

struct Node* insertAVL(struct Node* root, int data);
int NodeHeight(struct Node* root);
int BalanceFactor(struct Node* root);
struct Node* LLRotation(struct Node* root);

int main()
{
    struct Node*root = NULL ; 
    root = insertAVL(root,50);
    root = insertAVL(root,10);
    root = insertAVL(root,20);
    return 0 ; 
}

struct Node*insertAVL(struct Node*root,int data)
{
    if(root == NULL)
    {
        struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->left = NULL ; 
        newnode->data = data ; 
        newnode->right = NULL ;
        newnode->height = 1 ; 
        return newnode;
    }
    else if(data < root->data)
        root->left = insertAVL(root->left,data);
    else if(data > root->data)
        root->right = insertAVL(root->right,data);

    root->height = NodeHeight(root);

    if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
        LLRotation(root);

    return root ; 
}

int NodeHeight(struct Node *root)
{
    int heightLeft, heightRight;

    if(root == NULL)
        return 0 ; 

    if(root->left != NULL)
        heightLeft = root->left->height;
    else 
        heightLeft = 0;


    if(root->right != NULL)
        heightRight = root->right->height;
    else
        heightRight = 0;


    if(heightLeft > heightRight)
        return heightLeft + 1;
    else
        return heightRight + 1;
}

int BalanceFactor(struct Node*root)
{
    int heightLeft, heightRight;
    if(root == NULL)
        return 0 ;
    
    if(root->left !=NULL)
        heightLeft = root->left->height;
    else 
        heightLeft = 0;

    if(root->right != NULL)
        heightRight = root->right->height;
    else
        heightRight = 0;
    
    return heightLeft - heightRight ;
}

struct Node * LLRotation(struct Node *root)
{
    struct Node*root1 =root ; 

    struct Node*pl=root1->left;

    struct Node *plr=pl->left;
    
    pl->right=root1;
    root1->left=plr;
    
    if(root == root1)
        root = pl;
    
    return pl;
}