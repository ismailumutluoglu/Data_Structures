// #Inserting a Binary Search Tree

// void insertBST(Node*t , int data)
// {
//     Node*p = NULL , *newnode ;

//     while(t != NULL)
//     {
//         p = t ; 

//         if(data == t->data)
//             return ; 
//         else if(data < t->data)
//             t = t->left ; 
//         else
//             t = t->right ; 
//     }
//     newnode = (struct Node*)malloc(sizeof(struct Node);
//     newnode->left = NULL ;
//     newnode->data = data ; 
//     newnode->right = NULL ; 
//     if(newnode->data < p->data)
//         p->left = newnode ; 
//     else
//         p->right = newnode ; 
// }


// #Recursive Inserting in a BST

// int main
// {
//     Node*root = NULL ; 
//     root = insert(root,30);
//     root = insert(root,20); #rootlar birinci satırdan sonra olmasada olur.
//     root = insert(root,40); #rootlar birinci satırdan sonra olmasada olur.
//     root = insert(root,50); #rootlar birinci satırdan sonra olmasada olur.
//     root = insert(root,60); #rootlar birinci satırdan sonra olmasada olur.
//     root = insert(root,10); #rootlar birinci satırdan sonra olmasada olur.
//     root = insert(root,90); #rootlar birinci satırdan sonra olmasada olur.
//     return 0 ;
// }

// Node*insertBST(Node*root,int data)
// {
//     Node*newnode = NULL ;

//     if(root == NULL)
//     {
//         newnode = (struct node*)malloc(sizeof(struct Node)) ;
//         newnode->left = NULL ; 
//         newnode->data = data ;
//         newnode->right = NULL ;
//         return newnode ; 
//     }
//     else if(data < root->data)
//         root->left = insertBST(root->left,data) ; 
//     else 
//         root->right = insertBST(root->right,data);

//     return root ; 
// }