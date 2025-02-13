void maxHeapify(int arr[] , int i , int N)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i ; 

    if(left <  N && arr[left] > arr[largest])
    {
        largest = arr[left];
    }

    if(right < N && arr[right] > arr[largest])
    {
        largest = arr[right];
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(arr,largest,N);
    }
}

void convertMaxHeap(int arr[] , int N)
{
    for(int i = N/2 - 1 ; i>=0 ; i--)
    {
        maxHeapify(arr,i,N);
    }
}