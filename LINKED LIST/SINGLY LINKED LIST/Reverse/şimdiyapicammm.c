#include <stdio.h>
#include <stdlib.h>

    struct node
    {
        int data ; 
        struct node* next ; 
    };
    struct node*head = NULL ,*newnode ; 

    int main()
    {
        int choise = 1 ; 
        int i = 0 ;  
        //create
        while(choise)
        {
            if(head == NULL)
            {
                head = (struct node*)malloc(sizeof(struct node));
                newnode = head ; 
            }
            else
            {
                newnode->next = (struct node*)malloc(sizeof(struct node));
                newnode = newnode->next ; 
            }
            newnode->next = NULL ; 

            printf("enter data");
            scanf("%d",&newnode->data);

            printf("1-devam 0-cikis");
            scanf("%d",&choise);
        }
        //reverse 
        struct node*prev,*current,*next ;
        prev = NULL ; 
        current = next = head ; 
        while(next != NULL)
        {
            next = next->next ; 
            current->next = prev ; 
            prev = current ; 
            current = next ; 
        }
        head = prev ; 

        struct node*temp = head ; 
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next ; 
        }
        return 0 ; 
    }