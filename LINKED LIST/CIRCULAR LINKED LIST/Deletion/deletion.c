#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next ; 
};

struct node*head = NULL ;
struct node*temp ; 

struct node*deletion(struct node*head,int key,struct node*tail);
void display();

int main()
{
    int choise = 1 ; 

    while(choise)
    {
        struct node*newnode; 
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL ; 
        printf("yeni dugumun verisini giriniz : "); scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = temp = newnode ; 
        }
        else
        {
            temp->next = newnode ; 
            temp = newnode ; 
        }
        temp->next = head ;
        printf("devam etmek icin 1 bitirmek icin 0 "); scanf("%d",&choise);
    }
    int key ;
    printf("anahtar girin : "); 
    scanf("%d",&key);
    head = deletion(head,key,temp);
    display();
    return 0 ; 
}

struct node*deletion(struct node*head,int key,struct node*tail)
{

    struct node*prev,*next;
    prev = next = head ;  

    if(head->data == key)
    {
        tail->next = head->next ;
        head = head->next ;  
        free(prev);
    }
    else
    {
        while(next->next != head && next->data != key)
        {
            prev = next ; 
            next = next->next ; 
        }
        if(next->next == head)
        {
            prev->next = head ; 
        }
        else
        {
            prev->next = next->next ; 
        }
        free(next);
    }
    return head ;
}

void display()
{
    struct node*temp = head ; 
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
