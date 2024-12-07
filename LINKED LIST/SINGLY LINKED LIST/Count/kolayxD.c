#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node* next ; 
};
struct node*head = NULL ,*newnode ; 
int count(struct node*head);
int main()
{
    int choise = 1 ; 
    int i = 0 ;  
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
    printf("%d",count(head));
}
int count(struct node*head)
{
    if(head != NULL)
        return 1 + count(head->next);
    else
        return 0 ; 
}