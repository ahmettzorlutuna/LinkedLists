#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n *next;
};

void print(n *r)
{
    while (r != NULL)
    {
        printf("%d ", r->x);
        r = r->next;
    }
}

void add(n *r, int x)
{
    while (r->next != NULL)
    {
        r = r->next;
    }
    r->next = (n *)malloc(sizeof(n));
    r->next->x = x;
    r->next->next = NULL;
}

n * addSequential(n*r, int x){ //Listenin root'u değişeceği için yeni root'u return edeceğiz o yüzden fonksiyonun n tipinde olması gerekli.
    if(r == NULL){ //Listenin boş olma durumu.
        r = (n*)malloc(sizeof(n));
        r -> next = NULL;
        r -> x = x;
        return r;
    }
    if(r -> x > x){ //Fonksiyona gönderilen x'in root'un x değerinden küçük olma durumu. Böylelikle ilk eleman yani root değişir
                    //o yüzden yeni root değerini return ettik.
        n *temp = (n*)malloc(sizeof(n));
        temp -> x = x;
        temp -> next = r;
        return temp;
    }
    n * iter = r; //Şimdiki şartta root'ta herhangi bir değişme olmayacağı için iter ile gezinmek zorundayız.
    while(iter -> next != NULL && iter -> next -> x < x){ //İter'in gösterdiği kutunun x değeri bizim gönderdiğimiz x değerinden büyük
                                                         //olmadığı sürece ve iter'in next'i null olmadığı sürece devam et. Zaten iter'in next'i
                                                        //Null ise son'a ekler. 
        iter = iter -> next;
    }
    n *temp = (n*)malloc(sizeof(n));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    return r;
}

// Malloc hafızada bir kutu konulabilecek yer ayırtır.
int main()
{
    n *root; // Root struct'ı oluşturuldu. İlk n elemanı (root)
    root = NULL;
    root = addSequential(root, 400);
    root = addSequential(root, 50);
    root = addSequential(root, 150);
    root = addSequential(root, 20);
    root = addSequential(root, 200);
    print(root);
}
