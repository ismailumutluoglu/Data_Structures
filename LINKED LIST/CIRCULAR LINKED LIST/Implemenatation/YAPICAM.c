#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next ; 
};
struct node*head = NULL ; 

struct node*createList(struct node*head);
void displayList();
int main()
{
    head = createList(head);
    head = createList(head);
    head = createList(head);
    displayList();
    return 0 ; 
}

struct node*createList(struct node*head)
{
    struct node*newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node)); 
    printf("yeni dugumun verisini girer misin canim ") ; 
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = temp = newnode ; // acil durum
    }
    else
    {
        temp->next = newnode ; 
        temp = temp->next ; 
    }
    temp->next = head ; 

    return head ; 
}

void displayList()
{
    struct node*temp = head ; 

    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
