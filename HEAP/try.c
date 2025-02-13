#include <stdio.h> 
#include <stdlib.h>

// Fonksiyon prototipleri
void Insert(int heap[], int size);
int Delete(int heap[], int size);

int main()
{ 
    // Yığın (Heap) dizisi. İlk eleman dummy (0) olarak kullanılıyor.
    int heap[] = {0, 14, 15, 5, 20, 30, 8, 40}; 
    int i; 

    // Yığın oluşturma: Elemanları tek tek yığına ekliyoruz.
    for (i = 2; i <= 7; i++)
    {
        Insert(heap, i); 
    } 
        

    // Yığın sıralama: Elemanları teker teker siliyoruz.
    for (i = 7; i > 1; i--) 
    {
        printf("%d ",Delete(heap, i)); 
    }
    
    printf("\n");
    // Sıralı yığın elemanlarını yazdırma
    for (i = 1; i <= 7; i++) 
        printf("%d ", heap[i]); 
    printf("\n"); 

    return 0; 
} 

// Yığına eleman ekleme (Insert) fonksiyonu
void Insert(int heap[], int size) 
{ 
    int index = size; // Yeni elemanın ekleneceği dizin
    int value = heap[index]; // Yeni elemanın değeri dizinin son elemanı olmalı 

    // Ebeveyn düğümüyle karşılaştır ve yukarı taşı
    while (index > 1 && value > heap[index / 2]) 
    { 
        heap[index] = heap[index / 2] ; // Ebeveyn düğümünü aşağı taşı
        index = index / 2; // Ebeveynin indeksine geç
    } 
    heap[index] = value; // Yeni elemanı doğru yere yerleştir
} 

// Yığından eleman silme (Delete) fonksiyonu
int Delete(int heap[], int size) 
{ 
    int i = 1, j = 2 * i; // Kök düğümden başlayarak aşağı hareket et
    int value = heap[1]; // Silinecek (kök) eleman
    int last = heap[size]; // Son eleman

    heap[1] = last; // Son elemanı köke taşı
    heap[size] = value ; // Silinen elemanı sona yerleştir (sıralama için)

    // Yığına yeniden düzenleme (heapify)
    while (j <= size - 1)
    { 
        // Sağ çocuk daha büyükse sağ çocuğa geç
        if (j < size - 1 && heap[j + 1] > heap[j]) 
            j = j + 1; 

        // Ebeveyn düğüm küçükse yer değiştir
        if (heap[i] < heap[j]) 
        { 
            //swap işlemi yapılıyor
            int temp = heap[i]; 
            heap[i] = heap[j]; 
            heap[j] = temp; 

            i = j; // Çocuk düğüme geç // çocuk düğüm artık yeni parent
            j = 2 * i; // Çocuklarının indeksini güncelle , çocuk düğümler yeni parentin çocukları
        } 
        else 
            break; // Yığın düzeni korunuyorsa çık
    } 

    return value; // Silinen kök elemanını döndür
}