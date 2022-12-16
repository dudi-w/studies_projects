#include <stdio.h>
#include <stdbool.h>
#include "solution1.h"
/*
typedef struct stackArray
{
    int stack[SIZE];
    int buffer;
    buffer= SIZE;
}stackA;
*/

bool isEmpty(stackA stack){
    if(stack.buffer == SIZE){
        printf("The stack is ampty\n");
        return true;
        }
    return false;
}

bool isFull(stackA stack){
    if(stack.buffer<= 0){
        printf("The stack is Full\n");
        return true;
    }
    return false;
}

int pop(stackA* stack){
    if(!isEmpty(*stack)){
        int temp = (*stack).stack[(*stack).buffer];
        (*stack).stack[(*stack).buffer++]=(int long)NULL;
        free(temp);
        return temp;
    }
    return 0;
}

void push(stackA *stack ,int value){
    if(!isFull(*stack)){
        (*stack).stack[--(*stack).buffer] = value;
        }
    return;
}