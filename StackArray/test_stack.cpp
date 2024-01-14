#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

int main()
{
    stack *s1 = init();
    stack *s2 = init();
    for (int i = 1; i <= 10; i++)
    {
        push(i * 1, s1);
    }
    print(s1);
    for (int i = 0; i < 10; i++)
    {
        push(pop(s1), s2);
    }
    print(s2);
}