#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next ; 
};

struct node*front = NULL,*rear = NULL ;

void enqueue(int x );
// void dequeue();
void display();
int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    // dequeue();
    // dequeue();
    // display();
    // dequeue();
    // display();
    // dequeue();
    // display();
    // dequeue();
    // display();
    return 0 ; 
}
void enqueue(int x )
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x ; 
    newnode->next = NULL ; 

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode ; 
    }
    else
    {
        rear->next = newnode ; 
        rear = rear->next ; 
    }
}
void display()
{
    struct node*temp = front ; 
    if(front == NULL && rear == NULL)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
// void dequeue()
// {
//     if(front == NULL && rear == NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         struct node*temp = front ; 
//         front = front->next ; 
//         free(temp)
//     }
// }
