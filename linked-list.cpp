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
    while (r->next != NULL){
        r = r -> next;
    }
    r->next = (n *)malloc(sizeof(n));
    r->next->x = x;
    r->next->next = NULL;
}

// Malloc hafızada bir kutu konulabilecek yer ayırtır.
int main()
{
    n *root; // Root struct'ı oluşturuldu. İlk n elemanı (root)
    root = (n *)malloc(sizeof(n));
    root -> next = NULL;
    root->x = 500;

    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        add(root, i*10);
    }
    print(root);
}

