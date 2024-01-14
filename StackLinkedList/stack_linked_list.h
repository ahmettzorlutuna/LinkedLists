#ifndef stack_linked_list
#define stack_linked_list
struct n
{
    n *next;
    int data;
}; 
typedef n node;
int pop(node *);
node * push(node *, int);
#endif