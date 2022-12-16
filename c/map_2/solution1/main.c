#include <stdio.h>
#include "solution1.h"
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    /*stackA stack= NEW_STACK_A;
    pop(&stack);
    for(int i=-2 ; i<SIZE+1 ; ++i)
    {
        push(&stack , i);
    }
    
    isFull(stack);
    while (!isEmpty(stack))
    {
        printf("%d->" ,pop(&stack));
    }
    
    pop(&stack);
    return 0;
    */

    struct StackList *stack = NULL;
    pop2(&stack);
    for(int i=-2 ; i<18 ; ++i)
    {
        push2(&stack , i);
    }
    printList(stack);
    while (!isEmpty2(stack))
    {
        printf("%d->" ,pop2(&stack));
    }
    
    pop2(&stack);
    return 0;
}