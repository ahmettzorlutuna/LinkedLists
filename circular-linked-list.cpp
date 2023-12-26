#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n *next;
};

typedef n node;


void print(node *r)
{
    node *iter = r;
    printf("%d",iter->x);
    iter = iter -> next;
    while (iter != r)
    {
        printf("%d ", iter->x);
        iter = iter->next;
    }
}

void add(node *r, int x)
{
    node *iter = r;
    while (iter->next != r)
    {
        iter = iter -> next;
    }
    iter->next = (node *)malloc(sizeof(node));
    iter->next->x = x;
    iter->next->next = r;
}

node * addSequential(node*r, int x){ //Listenin root'u değişeceği için yeni root'u return edeceğiz o yüzden fonksiyonun node tipinde olması gerekli.
    if(r == NULL){ //Listenin boş olma durumu.
        r = (node*)malloc(sizeof(node));
        r -> next = r; //Liste boşsa yeni bir eleman oluşturduk ve next'i yeniden root'u yani kendisini gösteriyor.
                       // <-[]->
        r -> x = x;
        return r;
    }
    if(r -> x > x){ //Fonksiyona gönderilen x'in root'un x değerinden küçük olma durumu. Böylelikle ilk eleman yani root değişir
                    //o yüzden yeni root değerini return ettik. Buradaki tek fark circular linked list olduğu için en sondaki elemanın
                    //root u göstermesi yerine sıralı eklediğimiz için temp'i gösteriyor. Return ettiğimiz için de yeni root temp olarak başlıyor.
        node *temp = (node*)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        node *iter = r;
        while (iter -> next != r)
        {
            iter = iter -> next;
        }
        iter -> next = temp;
        return temp;
    }
    node * iter = r; //Circular Linked Listte araya eleman eklemenin bir farkı yok. Tek fark iter'in next'i null olana kadar değil de R yani
                     //root'u göstermeyene kadar git dedik. bkz. inserting-elements.cpp 45:9
    while(iter -> next != r && iter -> next -> x < x){ 
        iter = iter -> next;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    return r;
}

// Malloc hafızada bir kutu konulabilecek yer ayırtır.
int main()
{
    node *root; // Root struct'ı oluşturuldu. İlk n elemanı (root)
    root = NULL;
    root = addSequential(root, 400);
    root = addSequential(root, 50);
    root = addSequential(root, 150);
    root = addSequential(root, 20);
    root = addSequential(root, 200);
    print(root);
}
