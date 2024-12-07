#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*prev;
    struct node*next ; 
};

struct node*fibonacciFunction(struct node*head) ;
void displayFibonacciFunction(struct node*head) ;

struct node* head = NULL ; 

int main()
{
   
    head = fibonacciFunction(head);
    displayFibonacciFunction(head);
    return 0 ; 
}

struct node* fibonacciFunction(struct node*head)
{
    struct node*temp,*newnode;
    int i = 0 ; 
    while (i < 10)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            newnode->data = 0 ; 
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode ;
            newnode->prev = temp ;
            temp = temp->next ;

            if(temp == head->next)
            {
                newnode->data = 1 ; 
            }
            else
            {
                newnode->data = newnode->prev->data + newnode->prev->prev->data ; 
            }
        }
        i++;
    }
    return head ; 
}

void displayFibonacciFunction(struct node*head)
{
    struct node*temp = head ; 
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
}
