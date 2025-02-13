#include <stdio.h>
#include <stdlib.h>

void createHeap();
void insertHeapFunction(int array[] , int N);

int main()
{
    createHeap() ; 
}
//creating Heap
void createHeap()
{
    int array[] = {0,10,20,30,25,5,40,35} ; 
    
    for(int i = 2 ; i <= 7 ; i++)
    {
        insertHeapFunction(array,i) ; 
    }
}
//insert heap !! 
void insertHeapFunction(int array[] , int N)
{
    int temp , i = N ; 

    temp = array[N] ; 

    while(i > 1 && temp < array[i/2])
    {
        array[i] = array[i/2] ; 
        i = i/2 ; 
    }  
    array[i] = temp ;

    for(int j = 0 ; j < N ; j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n") ; 
}