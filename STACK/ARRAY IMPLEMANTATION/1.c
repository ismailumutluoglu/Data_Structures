#include <stdio.h>

#define SIZE 5 
int stack[SIZE];
int top = -1 ; 

void push();
void pop();
void peek();
void display();
int main()
{
    int ch ; 
    do
    {
        printf("enter your choice\n");
        printf("1-push\n2-pop\n3-peek\n4-display\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1 : push();
                break;
            case 2 : pop();
                break ; 
            case 3 : peek();
                break ; 
            case 4 : display();
                break ; 
            default : printf("Invalid choice");
        }
    } while (ch);
    
    return 0 ; 
}
void push()
{
    int x ; 
    printf("enter value ");
    scanf("%d",&x);

    if(top == SIZE-1)
    {
        printf("stack is full");
    }
    else
    {
        top++;
        stack[top] = x ; 
    }
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
        printf("%d\n",item);
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
        printf("%d\n",stack[top]);
    }
}

void display()
{
    for(int i = top ; i >= 0 ; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}