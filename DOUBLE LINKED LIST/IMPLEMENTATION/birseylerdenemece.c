#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *createDoubleLinkedList(struct node *head);
void displayDoubleLinkedList(struct node *head);
int main()
{
    int choice;
    printf("1-create\n2-display\n0 bitir\n");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            head = createDoubleLinkedList(head);
            break;
        case 2:
            displayDoubleLinkedList(head);
            break;
        default:
            break;
        }
        printf("1-create\n2-display\0 bitir");
        scanf("%d", &choice);
    }
    return 0;
}
struct node *createDoubleLinkedList(struct node *head)
{
    struct node *newnode, *temp;
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("datayi giriniz");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
        printf("0 bitir 1 devam et"); scanf("%d",&choice);
    }

    return head;
}
void displayDoubleLinkedList(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}