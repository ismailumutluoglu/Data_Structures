int isMaxHeap(int arr[] , int N)
{
    if(N <= 1 )
        return 1 ; 

    for(int i = 0 ; i < N ; i++)
    {
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < N && arr[i] < arr[left])
            return 0 ; 
        
        if(right < N && arr[i] < arr[right])
            return 0 ; 
    }
    return 1 ; 
}