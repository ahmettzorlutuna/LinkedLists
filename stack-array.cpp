#include <stdio.h>
#include <stdlib.h>
#include "stack-array.h"
int pop()
{
    if(array == NULL){
        print("Array is empty");
        return -1;
    }
    if (top <= size / 4)
    { // Dizideki elemanların sayısı, dizinin boyutunun dörtte birinden küçükse.
        int *array2 = (int *)malloc(sizeof(int) * size / 2);
        for (int i = 0; i < size; i++)
        {
            array2[i] = array[i];
        }
        free(array);
        array = array2;
        size /= 2;
    }
    return array[--top];
}

void push(int a)
{
    if(array == NULL){
        array = (int *)malloc(sizeof(int) * 2);
    }
    if (top >= size)
    {
        int *array2 = (int *)malloc(sizeof(int) * size * 2);
        for (int i = 0; i < size; i++)
        {
            array2[i] = array[i];
        }
        free(array);
        array = array2;
        size *= 2;
    }
    array[top++] = a;
}

void print()
{
    printf("Size..: %d ",size);
    for (int i = 0; i < top; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(60);
    push(60);
    push(60);
    push(60);
    print();
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    push(70);
    push(80);
    push(80);
    push(80);
    push(80);
    push(80);
    push(80);
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    printf("popped..: %d ", pop());
    print();
}