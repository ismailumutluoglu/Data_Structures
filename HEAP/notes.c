// in heap height = logN only because it is complete binary tree

/*

in heap nodes left and right children formules

node(parent) = i ; 
node->left(left child) = 2i ; 
node->right(right child) = 2i+ 1 ; 

for example any nodes is child of any nodes how can ı find that node parent ? : 

node = 8 parent = 4 :) 
node = 9 parent = 4 :)



void Insert(int A[] , int N)
{
    int i = N ; 
    int temp = A[N] ;

    while(i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2] ; 
        i = i/2 ; 
    }
    A[i] = temp ;  
}

    
void delete(int A[] , int N)
{
    int last = A[N] ; 
    A[1] = last ; 
    
    int i = 1 ; 
    int j = 2*i ; 

    while(j < N-1)
    {
        if(A[j + 1 ] > A[j])
        {
            j = j + 1 ; 
        }

        if(A[i] > A[j])
        {
            int temp = A[i] ; 
            A[i] = A[j] ; 
            A[j] = temp ;
            i = j ; 
            j = 2*j ;
        }
        else
            break ; 
    }   
}










*/