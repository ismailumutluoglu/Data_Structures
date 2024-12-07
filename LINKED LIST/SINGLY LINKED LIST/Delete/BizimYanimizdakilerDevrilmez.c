#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node* next ; 
};
struct node*head = NULL,*newnode ; 

int main()
{
    int choise = 1 ;  
    //create
    while(choise)
    {
        if(head == NULL)
        {
            head = (struct node*)malloc(sizeof(struct node));
            newnode = head ; 
        }
        else
        {
            newnode->next = (struct node*)malloc(sizeof(struct node));
            newnode = newnode->next ; 
        }
        newnode->next = NULL ; 

        printf("enter data");
        scanf("%d",&newnode->data);

        printf("1-devam 0-cikis");
        scanf("%d",&choise);
    }
    //delete
    int choise2 = 1 ; 
    while(choise2)
    {
        struct node*current = head ; 
        struct node*prev = NULL ; 
        int key ; 
        printf("anahtar sayiyi giriniz : "); scanf("%d",&key);
        //bastan silme
        if(current->data == key)
        {
            head = current->next ; 
            free(current);
        }
        //sondan veya herhangi bir yerden silme
        else
        {
            while(current != NULL && current->data != key)
            {
                prev = current ; 
                current = current->next ; 
            }
            if(current == NULL)
            {
                prev->next = NULL ;
                free(current);
            }
            else
            {
                prev->next = current->next ; 
                free(current);
            }
        }
        printf("cikis icin 0 a tikla devam etmek icin 1");
        scanf("%d",&choise2);
    }
    //display
    struct node*temp = head ; 
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ;
    }
    return 0 ; 
}
