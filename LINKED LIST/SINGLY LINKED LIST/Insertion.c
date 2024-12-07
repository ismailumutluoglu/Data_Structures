#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ; 
    int no ;
    char name[50];
    struct node* next ; 
};
struct node*head = NULL ,*newnode; 

int main()
{
    int choise = 1 ; 
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

        printf("isim giriniz : ");
        scanf("%s",newnode->name);
        printf("data giriniz : ");
        scanf("%d",&newnode->data);
        printf("no  giriniz : ");
        scanf("%d",&newnode->no);

        printf("1-devam 0-cikis");
        scanf("%d",&choise);
    }

    //insertion list
    int choise2 = 1 ; 
    while(choise2)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        int key ;
        printf("anahtar kelimeyi giriniz : ");
        scanf("%d",&key);

        printf("eklenecek dugumun datasini giriniz : ");
        scanf(" %s",newnode->name);
        scanf("%d",&newnode->data);
        scanf("%d",&newnode->no);

        struct node*current = head ; 
        struct node*prev = NULL ; 

        if(current->no == key)
        {
            newnode->next = current ; 
            head = newnode;
        }
        else
        { 
            while(current  != NULL && current->no != key)
            {
                prev = current ; 
                current = current->next ; 
            }
            if(current == NULL)
            {
                prev->next = newnode ; 
                newnode->next = NULL ;
            }
            else
            {
                prev->next = newnode ; 
                newnode->next = current; 
            }
        } 

        printf("ekleme islemine devam etmek icin 1 i cikmak icin 0 i sec");
        scanf("%d",&choise2);
    }
    //display the list
    struct node*current = head ; 
    while(current != NULL)
    {
        printf("isim : %s\t",current->name);
        printf("data : %d\t",current->data);
        printf("no : %d\n",current->no);
        current = current->next ; 
    }
    return 0 ; 
}
