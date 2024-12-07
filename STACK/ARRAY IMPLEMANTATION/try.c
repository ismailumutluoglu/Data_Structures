#include <stdio.h>

#define SIZE 5 
int stack[SIZE];
int top = -1 ; 
void push(int x);
void display();
void peek();
void pop();
int main()
{
    push(7);
    push(8);
    push(9);
    push(1);
    push(2);
    push(3);
    display();
    peek();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    peek();
    display();
    pop();
    display();
    peek();
}
void push(int x)
{
    if(top == SIZE-1)
    {
        printf("stack is full");
    }
    else
    {
        top++;
        stack[top] = x ; 
    }
    printf("\n");
}
void display()
{
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        for(int i = top ; i > -1 ; i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void peek()
{
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d ",stack[top]);
    }
    printf("\n");
}
void pop()
{
    int item ; 
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        item = stack[top];
        top--;
    }
}