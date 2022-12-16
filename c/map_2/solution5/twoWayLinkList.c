#include <stdio.h>
#include <stdlib.h>
#include "solution5.h"

// Function to add a new Cell tp beginning of the list.
void insert(Cell** head_ref, int new_data)
{
    Cell* new_Cell  = (Cell*)malloc(sizeof(Cell));
    new_Cell->data = new_data;
    if ((*head_ref)!=NULL)
        (*head_ref)->prev = new_Cell;
    new_Cell->next = (*head_ref);
    new_Cell->prev = NULL;
    (*head_ref) = new_Cell;
}

// Function to remove the first Cell
int removeFirst( Cell** head_ref){
    if((*head_ref)==NULL)
        return ;
    Cell * temp = (*head_ref);
    (*head_ref)= (*head_ref)->next;
    (*head_ref)->prev =NULL;
    int value = temp->data;
    free(temp);
    return value;
}

// Function to print linked list
void printList(Cell* head)
{
    printf("The tow way linked list is:\n head ->");
    for(Cell* temp = head; temp!= NULL ; temp = temp->next)
        printf("%d ->", temp->data);
    printf("NULL\n");
}

//Function to print linked list in revers order
void printRevers(Cell * head){
    printf("The tow way revers linked list is: \n NULL ->");

    Cell* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    while (temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->prev;
    }
    printf("head\n");     
}