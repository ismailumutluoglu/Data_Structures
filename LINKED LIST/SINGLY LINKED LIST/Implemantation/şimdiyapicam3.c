#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data ; 
    struct node* next ; 
};
struct node*head = NULL ,*newnode,*temp;

int main()
{
    // creat list
    int choise = 1 ; 
    while(choise)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next = NULL ; 

        if(head == NULL)
        {
            head = temp = newnode ; 
        }
        else
        {
            temp->next = newnode ; 
            temp = newnode ; 
        }

        printf("do you want to continue");
        scanf("%d",&choise);
    }

    temp = head ; 
    //display list 
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
}