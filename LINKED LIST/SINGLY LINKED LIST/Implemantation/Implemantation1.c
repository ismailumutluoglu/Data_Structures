#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id ; 
    struct Student* next ; 
};

struct Student* head = NULL ,*newNode ;

void creatList();
void readList();
int main()
{
    int choise ;
    while(1)
    {
        printf("1-liste olustur/ekle\n2- listeyi oku\n3-cikis\n");
        printf("secimi yap : ");
        scanf("%d",&choise);
        
        switch(choise)
        {
            case 1 : creatList();
            break ; 
            case 2 : readList();
            break ;
            case 3 : exit(0) ; 
        }
    }
    return 0 ; 
}
void creatList()
{
    if(head == NULL)
    {
        head = (struct Student*)malloc(sizeof(struct Student));
        newNode = head ;  
    }
    else
    {
        newNode->next = (struct Student*)malloc(sizeof(struct Student));
        newNode = newNode->next ; 
    }
    printf("ogrencinin numarasini giriniz : ");
    scanf("%d",&newNode->id);
    newNode->next = NULL ; 
}
void readList()
{
    struct Student* node = head ; 

    while(node != NULL)
    {
        printf("id : %d\n",node->id);
        node = node->next ; 
    }
}