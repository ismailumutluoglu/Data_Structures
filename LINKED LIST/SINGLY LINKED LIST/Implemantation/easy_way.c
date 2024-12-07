#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next;
};

struct node*head = NULL ; 
struct node*createList(struct node*head,int x);
void display(struct node*head);
int main()
{
    head = createList(head,5);
    head = createList(head,6);
    head = createList(head,7);
    head = createList(head,8);
    head = createList(head,9);
    display(head);
    return 0 ; 
}

struct node*createList(struct node*head,int x)
{
    struct node*newnode;

    if(head == NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        head = newnode ; 
    }
    else
    {
        newnode->next = (struct node*)malloc(sizeof(struct node));
        newnode = newnode->next ; 
    }
    newnode->data = x ; 
    newnode->next = NULL ;
    return head ; 
}
void display(struct node*head)
{
    struct node*temp = head ; 

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
}
