#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node*prev ;
    struct node*next ;
};

struct node*head = NULL ; 
struct node*tail ; 
struct node*insertAtBeginning(struct node*head);
struct node*insertAtRandom(struct node*head);
struct node*insertAtEnd(struct node*head);
void displaylist(struct node*head);

int main()
{
    int choice = 1 ; 
    while(choice)
    {
        struct node*newnode ; 
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->prev = NULL ; 
        newnode->next = NULL ;
        printf("data giriniz\n",newnode->data);
        scanf("%d",&newnode->data);
        if(head == NULL)
        {
            head = tail = newnode ; 
        }
        else
        {
            tail->next = newnode ; 
            newnode->prev = tail ; 
            tail = newnode ; 
        }
        printf("devam etmek icin 1 bitirmek icin 0\n");
        scanf("%d",&choice);
    }
    // basa ekleme
    head = insertAtBeginning(head);
    displaylist(head);
    // ortaya ekleme
    head = insertAtEnd(head);
    displaylist(head);
    // sona ekleme
    head = insertAtRandom(head);
    displaylist(head);
}

struct node*insertAtBeginning(struct node*head)
{
    struct node*newnode ; 
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("basa eklenecek olan verinin datasini giriniz\n");
    scanf("%d",&newnode->data);

    newnode->prev = NULL ; 
    newnode->next = head ; 
    head->prev = newnode ; 
    head = newnode ; 
    return head ; 
}

struct node*insertAtRandom(struct node*head)
{
    int position ; 
    printf("random eklenecek olan data hangi pozisyonda olsun ?\n");
    scanf("%d",&position);

    struct node*temp,*newnode,*prev ; 
    temp = prev = head ; 
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("random eklenecek olan dugumun datasini giriniz\n");
    scanf("%d",&newnode->data);
    newnode->next = NULL ; 
    newnode->prev = NULL ;

    for(int i = 0 ; i < position-1 ; i++)
    {
        prev = temp ; 
        temp = temp->next ; 
    }
    prev->next = newnode ; 
    newnode->prev = prev ; 
    newnode->next = temp ; 
    temp->prev = newnode ;
    return head ; 
}

struct node*insertAtEnd(struct node*head)
{
    struct node*newnode ; 
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("sona eklenecek olan verinin datasini giriniz\n");
    scanf("%d",&newnode->data);
    tail->next = newnode ; 
    newnode->prev = tail ; 
    newnode->next = NULL ;
    tail = newnode ; 
    return head ; 
}

void displaylist(struct node*head)
{
    struct node*temp = head ; 

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
    printf("\n");
}
