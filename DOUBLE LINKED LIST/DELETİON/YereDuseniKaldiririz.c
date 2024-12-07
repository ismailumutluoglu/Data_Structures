#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*prev ; 
    struct node*next ; 
};

struct node*head = NULL ; 
struct node*deletion(struct node*head,int key);
void display();
int main()
{
    int choice = 1 ; 
    while(choice)
    {
        struct node*newnode,*temp; 
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->prev = NULL ; 
        newnode->next = NULL ; 
        printf("data giriniz"); scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = temp = newnode ; 
        }
        else
        {
            temp->next = newnode ; 
            newnode->prev = temp ; 
            temp = temp->next ; 
        }
        printf("1-devam , 0 cikis"); scanf("%d",&choice);
    }

    int key ; 
    printf("anahtar kelimeyi giriniz"); scanf("%d",&key);
    head = deletion(head,key);
    display();
    return 0 ; 
}
struct node*deletion(struct node*head,int key)
{
    struct node*temp,*prev ; 
    temp = head ; 
    if(head->data == key)
    {
        head = head->next ;  
        head->prev = NULL ; 
        free(temp);
    }
    else
    {
        while(temp->next != NULL && temp->data != key)
        {
            prev = temp ; 
            temp = temp->next ; 
        }
        if(temp->next == NULL)
        {
            prev->next = NULL ; 
        }
        else
        {
            prev->next = temp->next  ; 
            temp->next->prev = prev ;
        }
        free(temp);
    }
    return head ; 
}
void display()
{
    struct node*temp = head ; 
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
}