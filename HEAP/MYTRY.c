#include <stdio.h>
#include <stdlib.h>

void Insert(int heap[],int size);
int Delete(int heap[] , int size);

int main()
{
    int heap[] = {0, 14, 15, 5, 20, 30, 8, 40}; 

    for(int i = 2 ; i <=7 ; i++)
        Insert(heap,i);
    
    for(int i = 7; i > 1 ; i--)
        printf("%d ",Delete(heap,i));

    printf("\n");
    for(int i = 1 ; i <= 7 ; i++)
        printf("%d ",heap[i]);
    
    return 0 ; 
}

//max heap yapıyor . . .

void Insert(int heap[],int size)
{
    int i = size ; 
    int value = heap[i];

    while(i > 1 && value > heap[i/2])
    {
        heap[i] = heap[i/2];
        i = i/2 ; 
    }

    heap[i] = value ; 
}

int Delete(int heap[] , int size)
{
    int i = 1 ; 
    int j = 2*i ; 
    int value = heap[1] ; //silinecek eleman
    int last = heap[size]; //son eleman

    heap[size] = value ; //silinecek olanı yani en büyük olani sona at heap[1] i  (heapfy işlemi için . . .)
    heap[1] = last ; // en son elemani heap[1] e yani en basa at

    while(j < size-1 && j <= size-1)
    {
        //sağ çocuk sol çocuktan büyükse sağ çocuğa geç 
        if(heap[j+1] > heap[j])
        {
            j = j + 1 ; 
        }

        //kök eleman küçükse yer değiştiriyor
        if(heap[i] < heap[j])
        {
            int temp = heap[i] ; 
            heap[i] = heap[j] ; 
            heap[j] = temp ; 

            i = j ; 
            j = 2*i ; 
        }
        else
            break ; 
    }
    return value ; 
}