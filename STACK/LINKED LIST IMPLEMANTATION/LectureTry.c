#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5
struct node
{
    int data ; 
    struct node*next ; 
};

typedef struct
{
    struct node*top ; 
    int counter ; 
}stack; 
void initialize(stack*stk);
void pushOperation(stack*stk,int data);
void popOperation(stack*stk);
void displayOperation(stack*stk);
int main()
{
    stack s ; 
    initialize(&s);
    pushOperation(&s,5);
    pushOperation(&s,4);
    pushOperation(&s,8);
    pushOperation(&s,2);
    pushOperation(&s,1);
    popOperation(&s);
    popOperation(&s);
    displayOperation(&s);
    return 0 ;
}

void initialize(stack*stk)
{
    stk->top = NULL ; 
    stk->counter = 0 ; 
}

void pushOperation(stack*stk,int data)
{
    if(stk->counter == STACK_SIZE)
    {
        printf("STACK IS FULL");
    }
    else
    {
        struct node*temp ; 
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data ; 
        temp->next = stk->top ; 
        stk->top = temp ; 
        stk->counter++;
    }
}

void popOperation(stack*stk)
{
    struct node*temp = stk->top ; 
    if(stk->counter == 0)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        stk->top = stk->top->next ; 
        free(temp);
        stk->counter--;
    }
}

void displayOperation(stack*stk)
{
    while(stk->top != NULL)
    {
        printf("%d ",stk->top->data);
        stk->top = stk->top->next ; 
    }
}