#include <stdio.h>
#include <stdlib.h>

#define STRUCT_SIZE 5 

struct node
{
    int data ; 
    struct node*link;  
};

void push(int x);
void display();
void pop();
void peek();

struct node*top = NULL ; 

int main()
{
    push(6);
    push(7);
    push(11);
    push(5);
    push(6);
    push(1);
    push(2);
    push(3);
    push(-1);
    push(8);
    push(85);
    display();
    peek();
    pop();
    peek();
    display();
}
void push(int x)
{
    static int cnt = 0 ; 
    if(cnt == STRUCT_SIZE)
    {
        printf("stack is full");
    }
    else
    {
        struct node*newnode ; 
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x ; 
        newnode->link = top ; 
        top = newnode ; 
        cnt++;
    }
}
void display()
{
    struct node*temp;
    temp = top ; 
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link ; 
        }
        printf("\n");
    }
}
void pop()
{
    struct node*temp ; 
    temp = top ; 
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        top = top->link;
        free(temp);
    }
}
void peek()
{
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d\n",top->data);
    }
}