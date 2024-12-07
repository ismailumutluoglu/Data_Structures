#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10 

typedef struct LecturesNotes
{
    int data[STACK_SIZE];
    int top ;
}stack;

void Reset(stack *stk);
void PushOperation(stack *stk,int c);
void PopOperation(stack *stk);
void disPlayOperation(stack*stk);
int main()
{
    stack s; 
    Reset(&s);
    PushOperation(&s,5);
    PushOperation(&s,4);
    PushOperation(&s,3);
    PushOperation(&s,2);
    PushOperation(&s,1);
    PopOperation(&s);
    PopOperation(&s);
    disPlayOperation(&s);
    return 0 ; 
}

void Reset(stack *stk)
{
    stk->top = -1 ; 
}

void PushOperation(stack *stk,int c)
{
    if(stk->top == STACK_SIZE-1)
    {
        printf("STACK IS FULL");
    }
    else
    {
        stk->top++;
        stk->data[stk->top] = c ; 
    }
}

void PopOperation(stack *stk)
{
    if(stk->top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        int x = stk->data[stk->top];
        stk->top--;
    }
}

void disPlayOperation(stack*stk)
{
    while(stk->top != -1)
    {
        printf("%d ",stk->data[stk->top]);
        stk->top--;
    }
    printf("\n");
}
