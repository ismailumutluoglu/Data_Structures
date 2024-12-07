#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* createList(struct node *head);
void display(struct node*head);

int main()
{
    head = createList(head);
    display(head);
    return 0;
}

struct node* createList(struct node *head)
{
    struct node *newnode,*temp; 
    int choise = 1;
    while (choise)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("data giriniz");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = temp =  newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        temp->next = head ; 
        printf("eklemeye devam etmek icin 1 e tiklayiniz bitirmek icin 0 a tiklayiniz ");
        scanf("%d", &choise);
    }
    return head ; 
}
void display(struct node*head)
{
    struct node*temp;
    temp = head ;  
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
