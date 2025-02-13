#include <stdio.h>
#include <stdlib.h>

// AVL ağacı için düğüm yapısı
struct Node
{
    int key;                    // Düğümün anahtar değeri . . . 
    struct Node* left;          // Sol alt ağaç
    struct Node* right;         // Sağ alt ağaç
    int height;                 // Düğümün yüksekliği
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* createNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;           // Yeni düğümün yüksekliği 1'dir
    return node;
}

// Düğümün yüksekliğini döndürür
int getHeight(struct Node* node)
{
    if (node == NULL) {
        return 0;
    }
    return node->height;
}
// Dengelilik faktörünü hesaplar
int getBalance(struct Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// AVL ağacına eleman ekleme
struct Node* insert(struct Node* node, int key)
{
    // 1. Standart BST ekleme işlemi
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;  // Aynı değer tekrar eklenmez
    }

    // 2. Yükseklik güncelleme
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (leftHeight > rightHeight)
    {
        node->height = 1 + leftHeight;
    }
    else
    {
        node->height = 1 + rightHeight;
    }

    // 3. Dengelilik kontrolü
    int balance = getBalance(node);
    
    // Dengesizlik durumları
    // Sol-Sol Durumu (LL)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Sağ-Sağ Durumu (RR)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Sol-Sağ Durumu (LR)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Sağ-Sol Durumu (RL)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Dengeli düğüm
}
struct Node* rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Rotasyonu gerçekleştir
    x->right = y;
    y->left = T2;

    // Yükseklikleri güncelle

    //y için
    if(getHeight(y->left) > getHeight(y->right))
        y->height = getHeight(y->left) + 1 ; 
    else if(getHeight(y->right) > getHeight(y->left))
         y->height = getHeight(y->right) +1 ; 
    // x için
    if(getHeight(x->left) > getHeight(x->right))
        x->height = getHeight(x->left) + 1 ; 
    else if(getHeight(x->right) > getHeight(x->left))
        x->height = getHeight(x->right) +1 ;    
    return x;  // Yeni kök
}

// Sol rotasyon
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Rotasyonu gerçekleştir
    y->left = x;
    x->right = T2;

    // Yükseklikleri güncelle
    
    if(height(x->left) > height(x->right))
        x->height = height(x->left) + 1 ; 
    else if(height(x->right) > height(x->left))
        x->height = height(x->right) + 1 ;
    return y;  // Yeni kök
}

// Ağacı sıralı (inorder) yazdırma 

void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Ana fonksiyon
int main()
{
    struct Node* root = NULL;

    // Elemanları AVL ağacına ekle
    int elements[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // AVL ağacını sıralı yazdır
    printf("AVL Ağacının sıralı gösterimi: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
