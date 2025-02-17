#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 
int queue[SIZE] ;
int front = -1 ; 
int rear = -1 ;

void enqueue(int x);
void display();

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    return 0 ; 
}

void enqueue(int x)
{
    if(rear == SIZE-1)
    {
        printf("STACK IS EMPTY");
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = x ; 
    }
    else
    {
        rear++;
        queue[rear] = x ; 
    }
}

void display()
{
    int i  ; 

    if(front == -1)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        for(int i = front ; i < SIZE ; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
