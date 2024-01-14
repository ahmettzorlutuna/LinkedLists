#ifndef stack_array
#define stack_array
struct s
{
    int size;
    int top;
    int * array;
};
typedef s stack;
stack *init();
int pop(stack *s);
void push(int, stack *s);
void print(stack *s);
#endif
