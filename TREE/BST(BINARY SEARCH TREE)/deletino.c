

struct node*findMin(struct node*root,int key)
{
    struct node*temp = root ; 

    while(temp != NULL && temp->left != NULL)
    {
        temp = temp->left ; 
    }
    return temp ; 
}
struct node*DeletionBST(struct node*root,int key)
{
    if(root == NULL)
        return NULL ; 
    
    if(key < root->data)
        deletion(root->left,key);
    else if(key > root->data)
        deletin(root->right,key);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL ;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            struct node*temp = root->left ; 
            free(root);
            return temp ; 
        }
        else if(root->left == NULL && root->right != NULL)
        {
            struct node*temp = root->right ; 
            free(root);
            return temp ; 
        }
        else
        {
            struct node*temp = findMin(root->right,key);
            root->data = temp->data ; 
            root->right = deletin(root->right,temp->key);
        }

    }
    return root ; 
}