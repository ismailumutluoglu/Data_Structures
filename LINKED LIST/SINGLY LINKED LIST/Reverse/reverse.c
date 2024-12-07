#include <stdio.h>
#include <stdlib.h>

struct studentInfo
{
    char name[50] ; 
    int id ;
    struct studentInfo* next ; 
};

struct studenInfo*head = NULL ; 

struct studentInfo* createAList(struct studentInfo*head);
struct studentInfo* reverseAList(struct studentInfo*head);
void displayList(struct studentInfo*head);

int main()
{
    head = NULL ; 

    while(1)
    {
        int choise ; 
        printf("1-CREATE  LIST\n");
        printf("2-DISPLAY LIST\n");
        printf("3-REVERSE LIST\n");
        printf("EXIT 0 ");
        scanf("%d",&choise);
        switch (choise)
        {
        case 0 : exit(0) ; 
        break ;
        case 1 : head = createAList(head);
            break;
        case 2 : displayList(head);
            break ; 
        case 3 : head = reverseAList(head); 
            break ; 
        }
    }
    return 0 ; 
}   

struct studentInfo*createAList(struct studentInfo*head)
{
    struct studentInfo*newNode ; 
    if(head ==  NULL)
    {
        head = (struct studentInfo*)malloc(sizeof(struct studentInfo));
        newNode = head ;
    }
    else
    {
        newNode->next = (struct studentInfo*)malloc(sizeof(struct studentInfo));
        newNode = newNode->next ; 
    }
    printf("isim giriniz : ");
    scanf("%s",newNode->name);
    printf("numara giriniz : ");
    scanf("%s",&newNode->id);
    newNode->next = NULL ; 
    return head ; 
}

struct studentInfo*reverseAList(struct studentInfo*head)
{
    struct studentInfo*prevNode,*currentNode,*nextNode ; 
    prevNode = NULL ; 
    currentNode = nextNode = head ; 
    while(nextNode != NULL)
    {
        nextNode = nextNode->next ; 
        currentNode->next = prevNode ; 
        prevNode = currentNode ; 
        currentNode = nextNode ; 
    }
    head = prevNode ;
    return head ; 
}
void displayList(struct studentInfo*head)
{
    struct studentInfo*temp = head ; 
    while(temp != NULL)
    {
        printf("%s %d\n",temp->name,temp->id);
    }
}
