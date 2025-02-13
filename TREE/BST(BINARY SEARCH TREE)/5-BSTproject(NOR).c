// binary search tree recursive fonk kullanmadan insert ve search
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*left ; 
    int data ; 
    struct Node*right ; 
};

struct Node*root = NULL ; 
 
void insertBST(int data);
void inorder(struct Node*p);
struct Node*SearchBST(int data);

int main()
{
    insertBST(10);
    insertBST(20);
    insertBST(30);
    insertBST(40);
    inorder(root);
    printf("\n");

    struct Node*control = SearchBST(31);
    if(control == NULL)
        printf("it is not found");
    else
         printf("it is  found");

    return 0 ; 
}

void insertBST(int data)
{
    struct Node* t = root;
    struct Node* r = NULL;
    struct Node* newnode ; 
    if (root == NULL)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->left = NULL ; 
        newnode->data = data ; 
        newnode->right = NULL ;
        return;
    }
    
    while (t != NULL)
    {
        r = t;
        if (data < t->data)
            t = t->left;
        else if (data > t->data)
            t = t->right;
        else
            return; // Aynı veri tekrar eklenmeyecek // burasi önemli !!
    }

    if (data < r->data)
        r->left = newnode;
    else
        r->right = newnode;
}

void inorder(struct Node*p)
{
    if(p !=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

struct Node*SearchBST(int data)
{
    struct Node*t = root  ; 

    while(t != NULL)
    {
        if(data < t->data)
            t = t->left ; 
        else if(data > t->data)
            t = t->right ;
        else
            return t ; 
    }
    return NULL ; 
}
