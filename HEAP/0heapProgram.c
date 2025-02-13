void Insertion(int heap[],int size)
{
    int value = heap[size] ; 
    int index = size ;

    while(index > 1 && heap[index] > heap[index/2])
    {
        heap[index] = heap[index/2];
        index = index / 2 ; 
    }
    heap[index] = value ; 
}

void Deletion(int heap[] , int size)
{
    int i = 1 ; 
    int j = 2*i ; 
    int last = heap[size];
    heap[1] = last ; 

    while(j <= size)
    {
        if(j < size - 1 && heap[j+1] > heap[j])
        {
            j = j + 1 ; 
        }

        if(heap[i] < heap[j])
        {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp ; 
            i = j ; 
            j = 2*i ; 
        }
        else
            break ; 
    }
}