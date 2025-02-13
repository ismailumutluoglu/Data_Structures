
// Node *RecursiveSearchTree(Node *root , int key)
// {
//     if(root == NULL)
//         return NULL ; 
//     else if(key == root->data)
//         return root ; 
//     else if(key < root->data)
//         return RecursiveSearchTree(root->left , key) ; 
//     else
//         return RecursiveSearchTree(root->right , key) ; 
// }


// Node *SearchTree(Node*root , int key)
// {
//     while(root != NULL)
//     {
//         if(key == root->data)
//             return root ; 
//         else if(key < root->data)
//             root = root->left ; 
//         else
//             root = root->right ; 
//     }
//     return NULL ; 
// }