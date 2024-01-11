#include <stdio.h>
#include <stdlib.h>
#include "stack-array.h"

int main(){
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