#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n *next;
    n * prev;
};

typedef n node;

void print(node *r)
{
    node *iter = r;
    printf("%d ", iter->x);
    iter = iter->next;
    while (iter != r)
    {
        printf("%d ", iter->x);
        iter = iter->next;
    }
    printf("\n");
}

node *addSequential(node *r, int x)
{ // Listenin root'u değişeceği için yeni root'u return edeceğiz o yüzden fonksiyonun node tipinde olması gerekli.
    if (r == NULL)
    { // Listenin boş olma durumu.
        r = (node *)malloc(sizeof(node));
        r->next = NULL; // Liste boşsa yeni bir eleman oluşturduk ve next'i yeniden root'u yani kendisini gösteriyor.
                     //  <-[]->
        r -> prev = NULL; //Çift bağlı linked listlerde next bir sonrakini gösterirken prev adlı bir öncekini gösteren yeni değerimiz de var artık.
        r->x = x;
        return r;
    }
    if (r->x > x)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        r -> prev = temp;
        return temp;
    }
    node *iter = r; // Circular Linked Listte araya eleman eklemenin bir farkı yok. Tek fark iter'in next'i null olana kadar değil de R yani
                    // root'u göstermeyene kadar git dedik. bkz. inserting-elements.cpp 45:9
    while (iter->next != r && iter->next->x < x)
    {
        iter = iter->next;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp -> prev = iter;
    if(iter -> next != NULL){
        temp -> next -> prev = temp;
    }
    temp->x = x;
    return r;
}

node *remove(node *r, int x)
{
    node *temp; // Silme işleminde yani değeri geçici olarak bir değişkende tutmak için.
    node *iter = r;
    if (r->x == x) // İlk elemanı silme
    {
        while (iter->next != r)
        {
            iter = iter->next;
        }
        iter->next = r->next; // İter son elemana geldiğinde iter son elemandan bir sonraki elemana eşit oluyor yani r -> next'ine.
        free(r) ;
        return iter->next;
    }
    while (iter -> next != r && iter -> next -> x != x){
        iter = iter->next;
    }
    if (iter->next == NULL)
    {
        printf("Number cannot found !");
        return r;
    }
    temp = iter->next;
    iter -> next = iter -> next -> next;
    free(temp);
    return r;
}

// Malloc hafızada bir kutu konulabilecek yer ayırtır.
int main()
{
    node *root;
    root = NULL;
    root = addSequential(root, 400);
    root = addSequential(root, 40);
    root = addSequential(root, 4);
    root = addSequential(root, 450);
    root = addSequential(root, 50);
    print(root);
    root = remove(root, 50);
    root = remove(root, 450);
    print(root);
}
