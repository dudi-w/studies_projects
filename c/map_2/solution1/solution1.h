#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#define NEW_STACK_A {.buffer=SIZE}
#define SIZE 10 
typedef struct Node node;
typedef struct stackArray stackA;

typedef struct stackArray
{
    int stack[SIZE];
    int buffer;
}stackA;

bool isEmpty(stackA stack);
bool isFull(stackA stack);
int pop(stackA *stack);
void push(stackA *stack ,int value);

struct StackList
{
    int data;
    struct StackList* next;
};
void insert(struct StackList** head_ref, int new_data);
void removeFirst(struct StackList** head_ref);
void printList(struct StackList* head);
void revers(struct StackList** head_ref);
bool isEmpty2(struct StackList* head);
int pop2(struct StackList** head_ref);
void push2(struct StackList** head_ref, int new_data);