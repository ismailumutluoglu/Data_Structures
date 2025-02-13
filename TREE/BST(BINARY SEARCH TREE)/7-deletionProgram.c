#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node
{
    int key;
    struct Node *left, *right;
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Ağaca düğüm ekleme fonksiyonu
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Minimum değere sahip düğümü bulma fonksiyonu
struct Node* findMin(struct Node* node)
{
    struct Node* current = node;
    while (current != NULL &&  current->left != NULL)
        current = current->left;
    return current;
}

// Ağacın bir düğümünü silme fonksiyonu
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return NULL ;

    // Silinecek düğümü bul
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // 1. Yaprak düğüm
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 2. Tek çocuk
        else if (root->left == NULL && root->right != NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp ;
        }
        else if (root->right == NULL && root->left != NULL)
        { 
            struct Node* temp = root->left ;
            free(root);
            return temp;
        }
        // 3. İki çocuk
        struct Node* temp = findMin(root->right);
        root->key = temp->key; // Successor'un değerini kopyala
        root->right = deleteNode(root->right, temp->key); // Successor'u sil
    }
    return root;
}

// Ağacı sıralı şekilde yazdırma (Inorder Traversal)
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

// Ana fonksiyon
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree: \n");
    inorder(root);

    printf("\n\nDelete 20\n");
    root = deleteNode(root, 20);
    inorder(root);

    printf("\n\nDelete 30\n");
    root = deleteNode(root, 30);
    inorder(root);

    printf("\n\nDelete 50\n");
    root = deleteNode(root, 50);
    inorder(root);

    return 0;
}
