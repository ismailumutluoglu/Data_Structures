#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node*next;
};

struct node*head = NULL  ,*temp ; 
struct node*insertion(struct node*head,struct node*tail);
void display();

int main()
{
    int choise = 1 ; 
    while(choise)
    {
        struct node*newnode ; 
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL ; 
        printf("dugumun verisin giriniz : "); scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = temp = newnode; 
        }
        else
        {   
            temp->next = newnode ; 
            temp = newnode ; 
        }
        temp->next = head ;
        printf("dugum eklemek icin 1 bitirmek icin 0 tusuna basiniz");
        scanf("%d",&choise);
    }

    head = insertion(head,temp);
    display();
    return 0 ;  
}
struct node*insertion(struct node*head,struct node*tail)
{
    struct node*newnode,*prev,*next; 
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("yeni eklenecek dugumun datasini giriniz : "); scanf("%d",&newnode->data);
    newnode->next = NULL ;
    int key ; 
    printf("anahtar sayiyi giriniz : "); scanf("%d",&key);
    prev = next = head ; 
    
    if(head->data == key)
    {
        newnode->next = prev ; 
        head = newnode ; 
        tail->next = head ; 
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
            next->next = newnode;
            newnode->next = head ; 
        }
        else
        {
            prev->next = newnode ;
            newnode->next = next ; 
        }
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
