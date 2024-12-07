#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

struct node
{
    int data ; 
    struct node*next;
};

typedef struct
{
    struct node*top ;
    int  cnt ; 
}stack;

void initialize(stack *stk);
void PushOperation(stack *stk,int x);
void PopOperation(stack* stk);
void displayOperation(stack *stk);

int main()
{
    stack s; 
    initialize(&s);
    PushOperation(&s,5);
    PushOperation(&s,4);
    PushOperation(&s,8);
    PushOperation(&s,2);
    PushOperation(&s,1);
    PopOperation(&s);
    PopOperation(&s);
    displayOperation(&s);
    return 0 ; 
}

void initialize(stack *stk)
{
    stk->top = NULL ; 
    stk->cnt = 0 ; 
}   

void PushOperation(stack *stk,int x)
{
    if(stk->cnt == STACK_SIZE)
    {
        printf("STACK IS FULL");
    }
    else
    {
        struct node*temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x ; 
        temp->next = stk->top ; 
        stk->top = temp ;
        stk->cnt++;
    }
}

void PopOperation(stack* stk)
{
    if(stk->cnt == 0)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        struct node*temp = stk->top ; 
        stk->top = stk->top->next ; 
        free(temp);
        stk->cnt--;
    }
}

void displayOperation(stack *stk)
{
    while(stk->top != NULL)
    {
        printf("%d ",stk->top->data);
        stk->top = stk->top->next ; 
    }
}