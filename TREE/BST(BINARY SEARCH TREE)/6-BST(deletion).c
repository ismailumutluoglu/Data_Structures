// 1. Yaprak Düğüm Silme (Hiç Çocuğu Yok)


// Yaprak düğüm, alt düğümü olmayan bir düğümdür.
// Bu durumda, düğüm doğrudan ağaçtan kaldirilir.


//     50
//    /  \
//   30   70
//  /
// 20

// 20 bir yaprak düğümdür. Silindiğinde, 30 düğümünün sol çocuğu null olur.

// 2. Tek Çocuğu Olan Düğüm Silme

// Silinecek düğümün yalnizca  bir çocuğu varsa, bu çocuk doğrudan silinen düğümün yerine geçer.
// Örneğin:


//     50
//    /  \
//   30   70
//    \
//    40

// 30 düğümü silinirse, 40 onun yerine geçer.

// Eğer sol çocuk varsa, silinen düğümün ebeveyni, sol çocuğunu bağlar.
// Eğer sağ çocuk varsa, ebeveyn sağ çocuğu bağlar.




// 3. İki Çocuğu Olan Düğüm Silme
// Bu durum en karmaşığıdır. İki seçenek vardır:

// Inorder Successor (Sonraki Düğüm):
// Silinecek düğümün sağ alt ağacında en küçük değere sahip düğüm bulunur.
// Bu değer silinecek düğümün yerine taşınır ve ardından bu düğüm (inorder successor) silinir.
// Inorder Predecessor (Önceki Düğüm):
// Silinecek düğümün sol alt ağacında en büyük değere sahip düğüm bulunur.
// Benzer şekilde bu düğüm silinecek düğümün yerine taşınır.

//     50
//    /  \
//   30   70
//  / \   / \
// 20 40 60 80

// 50 düğümü silindiğinde, ya 60 (successor) ya da 40 (predecessor) onun yerine geçer.
// Diyelim ki 60 seçildi. 60 kök düğüm olur ve eski yerindeki bağlantı (sağ alt ağaçta) düzenlenir.

//#########################################################################################################
// Minimum değere sahip düğümü bulma fonksiyonu

// struct Node* findMin(struct Node* node) {
//     struct Node* current = node;
//     while (current != NULL && current->left != NULL)
//         current = current->left;
//     return current;
// }

// Ağacın bir düğümünü silme fonksiyonu
// struct Node* deleteNode(struct Node* root, int key) {
//     if (root == NULL)
//         return root;

//      Silinecek düğümü bul
//     if (key < root->key)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->key)
//         root->right = deleteNode(root->right, key);
//     else {
//          1. Yaprak düğüm
//         if (root->left == NULL && root->right == NULL) {
//             free(root);
//             return NULL;
//         }
//         2. Tek çocuk
//         else if (root->left == NULL) {
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//          3. İki çocuk
//         struct Node* temp = findMin(root->right);
//         root->key = temp->key; // Successor'un değerini kopyala
//         root->right = deleteNode(root->right, temp->key); // Successor'u sil
//     }
//     return root;
// }


//#########################################################################################################

// CODING PART 

// struct node*DeletionBST(struct node*root,int data)
// {
//     if(root == NULL)
//         return NULL ; 
    
//     if(data < root->data)
//         root->left = DeletionBST(root->left,int data);
//     else if(data > root->data)
//         root->right = DeletionBST(root->right,int data);
//     else
//     {
//         çocuğu olmayan düğümse silme işlemi
//         if(root->left == NULL && root->right == NULL)
//         {
//             free(root);
//             return NULL ; 
//         }
//         tek çocuğu olan düğümler
//         else if(root->right == NULL && root->left != NULL)
//         {
//             struct node*temp = root->left ; 
//             free(root);
//             return temp ; 
//         }
//         else if(root->left == NULL && root->right != NULL)
//         {
//             struct node*temp = root->right ; 
//             free(root);
//             return temp ;
//         }
//         iki çocuğu olan düğümler
//         struct node*temp = findMin(root->right); 
//         root->data = temp->data ;
//         root->right = deletin(root->right,temp->data); //root a atadığımız değerin olduğu nodu siliyo
//     }
//     return root ; 
// }