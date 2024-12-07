#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    struct node*link ; 
};

struct node*top = NULL ; 
void push(int x);
void display();
void pop();
void peek();
int main()
{
    push(7);
    push(88);
    push(9);
    display();
    peek();
    pop();
    display();
    peek();
    return 0 ; 
}

void push(int x)
{
    struct node*newnode ; 
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x ; 
    newnode->link = top ; 
    top = newnode ; 
}

void display()
{
    struct node*temp = top ;
    if(top == NULL)
    {
        printf("stack is empty");
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link ; 
    } 
    printf("\n");
}

void pop()
{
    struct node*temp = top ; 
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        top = top->link ; 
        free(temp);
    }
} 


void peek()
{
    struct node*temp = top ; 
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d ",top->data);
    }
    printf("\n");
}