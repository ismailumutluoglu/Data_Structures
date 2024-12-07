#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*next ; 
};

struct node*front = NULL ; 
struct node*rear = NULL ; 

struct node*enqueue(struct node*front,int data)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data ; 
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
    return front ; 
}

void fonksiyon(int data)
{
    int number = data ; 
    int j = 1 ; 

    while(j <= number)
    {
        if(number % j == 0)
        {
            front = enqueue(front,j);
        }
        j++;
    }
}

void display()
{
    struct node*temp = front ; 

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next ; 
    }
}

int main()
{
    printf("0 ");
    fonksiyon(30);
    display();
    return 0 ; 
}