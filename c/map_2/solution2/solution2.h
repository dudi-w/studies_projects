#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//#include "stackList.c"

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

bool checkCompatibility(char const *argv, struct StackList **stackNum , struct StackList **stackOper);
void calculator(struct StackList **stackNum , struct StackList **stackOper);
