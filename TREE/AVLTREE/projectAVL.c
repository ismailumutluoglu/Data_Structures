#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node*left ; 
    int data ; 
    struct node*right ; 
    int height ; 
} ;

struct node*height(struct node*root);
struct node*getBalance(struct node*root);
struct node*rightRotation(struct node*root);
struct node*leftRotation(struct node*root);
struct node*create(int data);
struct node*insert(struct node*root,int data);

int main()
{
    struct node*root = NULL ; 

    root = insert(root,20);
    root = insert(root,15); 
    root = insert(root,25); 
    root = insert(root,40); 
    root = insert(root,35); 
    root = insert(root,23); 
    root = insert(root,80);

    return 0 ; 
}

struct node*getBalance(struct node*root)
{
    if(root == NULL)
        return 0 ; 
    else
        return height(root->left) - height(root->right);
}

struct node*height(struct node*root)
{
    if(root == NULL)
    {
        return 0 ; 
    }
    else
        return root->height ;
}

struct node*create(int data)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL ; 
    newnode->height = 1 ; 
    newnode->data = data ; 
    return newnode ; 
}

struct node*insert(struct node*root,int data)
{
    if(root == NULL)
    {
        return create(data);
    }
    else if(data < root->data)
        root->left = insert(root->left,data);
    else if(data < root->data)
        root->right = insert(root->right,data);
    else
        return root ; //datalar aynıysa tekrar ekleme yapmasın diye bu satırı ekliyoruz . 
    
    //yükseklik güncelleme kodu fazla uzatmadan recursive olarak . 

    if(height(root->left) > height(root->right))
        root->height = height(root->left) + 1  ; //+1 önemli bir detay
    else if(height(root->right) > height(root->left))
        root->height = height(root->right) + 1 ; 
    else
        root->height = height(root->left) + 1 || height(root->right) + 1 ; 
    //dengele kontrol 
    int balance = getBalance(root);

    //ROTASYON AYARLAMA !!

    //LL
    if(balance > 1 && data < root->left->data)
        return rightRotation(root);

    //RR
    if(balance < -1 && data > root->right->data)
        return leftRotation(root);

    //LR
    if(balance > 1 && data > root->left->right)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //RL
    if(balance < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root ;
}    

//SINAVDA SORMASI %80

struct node*rightRotation(struct node*y)
{
    struct node*x = y->left ; 
    struct node*T2 = x->right ; 

    x->right = y ; 
    y->left = T2 ; 

    //yükseklik güncellemesine geldik x ve y ayri ayri

    //y nin yükseliği 
    if(height(y->left) > height(y->right))
        y->height = height(y->left) + 1 ;
    else if(height(y->right) > height(y->left))
        y->height = height(y->right) + 1 ; 
    else
        y->height = height(y->left) + 1 ; // veya y->hight = height(y->right) + 1 

    //x in yüksekliği
    if(height(x->left) > height(x->right))
        x->height = height(x->left) + 1 ;
    else if(height(x->right) > height(x->left))
        x->height = height(x->right) + 1 ; 
    else
        x->height = height(x->left) + 1 ; // veya x->height = height(x->right ta olabilir) ikiside
    
    return x ; 
}
struct node*leftRotation(struct node*x)
{
    struct node*y = x->right ; 
    struct node*T2 = y->left ; 

    y->left = x ; 
    x->right = T2 ; 

    //yükseklik güncelleme

    //y nin yüksekliği
    if(height(y->left) > height(y->right))
        y->height = height(y->left) + 1 ; // + 1 önemli
    else if(height(y->right) > height(y->left))
        y->height = height(y->right) + 1 ; 
    else
        y->height = height(y->left) + 1 ; //veya y->height = height(y->right) + 1  farketmez . 
    //x in yüksekliği 
    if(height(x->left) > height(x->right))
        x->height = height(x->left) + 1 ;
    else if(height(x->right) > height(x->left))
        x->height = height(x->right) + 1 ; 
    else
        x->height = height(x->left) + 1 ; //veya x->height = height(x->right) + 1  fark etmez
    return y ; 
}
