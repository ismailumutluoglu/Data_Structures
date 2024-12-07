#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *kokolustur(int data){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *elemanEkle(struct node *root, int data){
    if(root== NULL){
        return kokolustur(data);
    }
    else{
        if(root->data > data)
            root->left=elemanEkle(root->left,data);
        else if(root->data < data)
            root->right=elemanEkle(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

void maxValue(struct node *root){
    struct node* temp= root;
    while(temp->right != NULL){
        temp=temp->right;
    }
    printf("max value is:%d\n",temp->data);
}


void minValue(struct node *root){
    struct node* temp= root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    printf("min value is:%d\n",temp->data);
}


int main(){
    root=elemanEkle(root,15);
    root=elemanEkle(root,9);
    root=elemanEkle(root,17);
    root=elemanEkle(root,8);
    root=elemanEkle(root,12);
    root=elemanEkle(root,16);
    root=elemanEkle(root,20);
    inorder(root);
    printf("\n");   
    maxValue(root);
    minValue(root);

    return 0;
}