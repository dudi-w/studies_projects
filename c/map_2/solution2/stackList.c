#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "solution2.h"

// Link list node
/*
struct StackList
{
    int data;
    struct StackList* next;
};
*/
// Function to add a new node
void insert(struct StackList** head_ref, int new_data)
{
    struct StackList* new_node = (struct StackList*)malloc(sizeof(struct StackList));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to remove the first node
void removeFirst(struct StackList** head_ref){
    if((*head_ref)==NULL)
        return;
    struct StackList* temp= (*head_ref);
    (*head_ref)= (*head_ref)->next; 
    free(temp);
}


// Function to print linked list
void printList(struct StackList* head)
{
    printf("The linked list is:\n");
    struct StackList* temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void revers(struct StackList** head_ref)
{
    struct StackList* first = *head_ref;
    struct StackList* tmp=NULL;
    while (first->next != NULL)
    {
        tmp = first->next;
        first->next = first->next->next;
        tmp->next=(*head_ref);
        (*head_ref)=tmp;
    }
}

bool isEmpty2(struct StackList* head){
    if((head)==   NULL){
        printf("The stack is ampty\n");
        return true;
        }
    return false;
}

int pop2(struct StackList** head_ref){
    if(!isEmpty2(*head_ref)){
        int temp = (*head_ref)->data;
        removeFirst(head_ref);
        return temp;
    }
    return 0;
}

void push2(struct StackList** head_ref, int new_data)
{
        insert(head_ref,  new_data);
}