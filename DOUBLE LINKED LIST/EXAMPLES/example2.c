// Write the destroy SLL function recursively

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next ; 
};

struct node*head = NULL,*temp; 
struct node*destroy(struct node*head);
void display();

int main()
{
    int choise = 1 ; 

    while(choise)
    {
        struct node*newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data : "); scanf("%d",&newnode->data);
        newnode->next = NULL; 
        if(head == NULL)
        {
            head = temp = newnode ; 
        }
        else
        {
            temp->next = newnode ; 
            temp = temp->next ; 
        }
        printf("eklemek icin 1 bitirmek icin 0 a tikla"); scanf("%d",&choise);
    }
    // display();
    head = destroy(head);
    display();
    return 0 ; 
}

struct node*destroy(struct node*head)
{
    struct node*temp = head ; 
    if(head != NULL)
    {
        head = head->next ; 
        free(temp);
        temp = head ; //bunu yazmayi unutma...
        return destroy(head) ; 
    }
    else
        return 0 ; 
}

void display()
{
    struct node*temp = head ; 
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
