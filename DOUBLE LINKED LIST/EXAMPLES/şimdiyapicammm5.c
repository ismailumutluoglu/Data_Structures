// Write a function that returns the number of nodes in a DLL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*prev ; 
    struct node*next ; 
};

struct node *head,*temp; 

int numbersOfNodes();
int main()
{
    int choise = 1 ; 

    while(choise)
    {
        struct node*newnode = (struct node*)malloc(sizeof(struct node));
        newnode->prev = newnode->next = NULL ; 
        printf(" Enter Data "); scanf("%d",&newnode->data);

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
        printf("devam etmek icin 1 cikmak icin 0 ");
        scanf("%d",&choise);
    }
    printf("%d",numbersOfNodes());
    return 0 ; 
}

int numbersOfNodes()
{
    struct node*temp = head ; 
    int i = 0 ; 
    while(temp != NULL)
    {
        i++;
        temp = temp->next ;
    }
    return i ; 
}