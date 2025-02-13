#include <stdio.h>
#include <stdlib.h>

void createHeap();
void insertHeapFunction(int array[] , int N);
int Delete(int array[] , int N) ; 

int main()
{
    createHeap() ; 
    return 0 ; 
}

//creating Heap
void createHeap()
{
    int array[] = {0,10,20,30,25,5,40,35} ; 
    
    for(int i = 2 ; i <= 7 ; i++)
    {
        insertHeapFunction(array,i) ; 
    }

    printf("%d",Delete(array,8));

    printf("\n");

    for(int j = 1 ; j <= 7 ; j++)
    {
        printf("%d ",array[j]);
    }

}
//insert heap !! 

void insertHeapFunction(int array[] , int N)
{
    int temp , i = N ; 

    temp = array[i] ;   

    while(i > 1 && temp > array[i/2])
    {
        array[i] = array[i/2] ; 
        i = i/2 ; 
    }  
    array[i] = temp ; 
}

int Delete(int array[] , int N)
{
    int value = array[1] ;  
    int last = array[N] ;
    array[1] = last ; 
    int i = 1 , j = 2*i ; 

    while(j < N - 1 )
    {
        if(array[j+1] > array[j])
        {
            j = j + 1 ;
        }
        
        if(array[i] < array[j])
        {
            int temp = array[i] ;
            array[i] = array[j] ; 
            array[j] = temp ; 

            i = j ; 
            j = 2*j ;  
        }
        else
            break ;  
    }
    array[N] = value ;
    return value ; 
}