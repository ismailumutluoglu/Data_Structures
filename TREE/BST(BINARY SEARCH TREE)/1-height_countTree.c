// #COUNTING NUMBER OF NODES RECURSIVELY

// int count(Node *root)
// {
//    
//     if(root == NULL)
//         return 0 ; 
//     else
//         return count(root->left) + count(root->right) + 1 ; 
// }


// int sumOfNodesData(struct node*root)
// {
//     if(root == NULL)
//         return 0 ;
//     else
//         return sumOfNodesData(root->left) + sumOfNodesData(root->right) + root->data ; 
// }

// #this code who have both children !!

// int count(Node *root)
// {
//     
//     if(root == NULL)
//         return 0 ; 
//     else
//     {
//         if(root->left != NULL && root->right != NULL)
//             return count(root->left) + count(root->right) + 1 ; 
//         else
//             return count(root->left) + count(root->right) ;
//     }
// }


// #this code finding leaf nodes !!

// int count(Node *root)
// {
//     if(root == NULL)
//         return 0 ; 
//     else
//     {
//         if(root->left == NULL && root->right == NULL)
//             return count(root->left) + count(root->right) + 1 ; 
//         else
//             return count(root->left) + count(root->right) ;
//     }
// }

// #this code how many nodes have at least one child

// int count(Node *root)
// {
//     if(root == NULL)
//         return 0 ; 
//     else
//     {
//         if(root->left != NULL || root->right != NULL)
//             return count(root->left) + count(root->right) + 1 ; 
//         else
//             return count(root->left) + count(root->right) ;
//     }
// }





// #this code is finding height of tree

// int height(struct node*Root)
// {
//     if(root == NULL)
//         return 0 ; 
    
//     if(height(root->left) > height(root->right))
//         return height(root->left) + 1 ; 
//     else if(height(root->right) > height(root->left))
//         return height(root->right) + 1 ; 
//     else
//         return height(root->left) + 1 || height(root->right) + 1 ; 
// }


// #just child how many node ara have it ? 

// Node *justOneChild(Node*root)
// {
//     if(root == NULL)
//         return 0 ; 
//     else
//     {
//         if((root->left == NULL && root->right != NULL) ||( root->left != NULL && root->right == NULL))
//             return justOneChild(root->left) + justOneChild(root->right) + 1 ; 
//         else
//             return justOneChild(root->left) + justOneChild(root->right)
//     }
// }
