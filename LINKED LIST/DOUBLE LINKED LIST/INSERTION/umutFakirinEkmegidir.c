#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data ; 
    struct node*prev ; 
    struct node*next ; 
};
struct node *insertion(struct node*head);
void display(struct node*head);
int main()
{
    int choice = 1 ; 
    struct node*head,*temp,*newnode;
    head = NULL ; 
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL ;
        newnode->prev = NULL ;
        printf("data giriniz"); scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode ; 
            newnode->prev = temp ; 
            temp = temp->next ; 
        }
        printf("1-devam 2-bitir");
        scanf("%d",&choice);
    }
    insertion(head);
    display(head);
}
struct node *insertion(struct node*head)
{
    struct node*newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL ;
    newnode->prev = NULL ;
    printf("data giriniz"); scanf("%d",&newnode->data);

    
}
void display(struct node*head)
{

}