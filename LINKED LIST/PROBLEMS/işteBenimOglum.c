#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int no ; 
    // char name[50] ;
    struct node*prev ; 
    struct node*next ;
};

struct node*head = NULL ; 
struct node*createAList(struct node*head);
void display();
void function();
int main()
{
    head = createAList(head);
    display();
    function();
    display();
    return 0 ; 
}

struct node*createAList(struct node*head)
{
    struct node*temp,*newnode ; 
    int ch = 1 ; 
    while(ch)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL ; 
        newnode->prev = NULL ;
        printf("yeni dugumun emplooyeNo sunu gir");
        scanf("%d",&newnode->no);
        // printf("yeni dugumun name sini gir");
        // scanf("%s",newnode->name);
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
        scanf("%d",&ch);
    }
    return head ; 
}

void display()
{
    struct node*temp = head ; 

    while(temp != NULL)
    {
        printf("%d ",temp->no);
        temp = temp->next;
    }
    printf("\n");
}

void function()
{
    struct node *newnode,*temp = head,*curr; 
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL ; 
    newnode->prev = NULL ; 
    printf("yeni dugumun verisini giriniz");
    scanf("%d",&newnode->no);

    if(newnode->no < head->no )
    {
        newnode->next = head ; 
        head->prev = newnode ; 
        head = newnode ;
    }
    else
    {
        while(temp->next != NULL && temp->no <= newnode->no)
        {
            curr = temp ; 
            temp  =  temp->next ; 
        }
        curr->next = newnode ; 
        newnode->next = temp ; 
        temp->prev = newnode ; 
    }
}