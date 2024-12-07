#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5 

typedef struct
{
    int stackArray[STACK_SIZE];
    int top ; 
}stack;

void resetStack(stack*stk);
void pushOperation(stack*stk,int data);
void popOperation(stack*stk);
void disPlayOperation(stack*stk);

int main()
{
    stack s; 
    resetStack(&s);
    pushOperation(&s,5);
    pushOperation(&s,4);
    pushOperation(&s,3);
    pushOperation(&s,2);
    pushOperation(&s,1);
    popOperation(&s);
    popOperation(&s);
    disPlayOperation(&s);
    return 0 ; 
}

void resetStack(stack*stk)
{
    stk->top = -1 ; 
}

void pushOperation(stack*stk,int data)
{
    if(stk->top == STACK_SIZE - 1 )
    {
        printf("STACK IS FULL");
    }
    else
    {
        stk->top++;
        stk->stackArray[stk->top] = data ; 
    }
}

void popOperation(stack*stk)
{
    int delete ; 
    if(stk->top == -1)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        delete = stk->stackArray[stk->top];
        stk->top--;
    }
}

void disPlayOperation(stack*stk)
{
    for(int i = stk->top ; i > -1 ; i--)
    {
        printf("%d ",stk->stackArray[stk->top--]);
    }
    // these are same things ; 
    while(stk->top != -1)
    {
        printf("%d ",stk->stackArray[stk->top--]);
    }
}