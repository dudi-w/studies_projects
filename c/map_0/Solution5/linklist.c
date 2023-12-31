#include <stdio.h>
#include <stdlib.h>
// Link list node
struct Node
{
    int data;
    struct Node* next;
};

// Function to add a new node
void insert(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to remove the first node
void removeFirst(struct Node** head_ref){
    if((*head_ref)==NULL)
        return;
    struct Node * temp =(*head_ref);
    (*head_ref)= (*head_ref)->next;
    free(temp);
}

// Function to print linked list
void printList(struct Node* head)
{
    printf("The linked list is:\n");
    //struct Node* temp = head;
    while (head != NULL)
    {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void revers(struct Node** head_ref)
{
    struct Node* first = *head_ref;
    struct Node* tmp=NULL;
    while (first->next != NULL)
    {
        tmp = first->next;
        first->next = first->next->next;
        tmp->next=(*head_ref);
        (*head_ref)=tmp;
    }
}
int main()
{
// Start with the empty list
struct Node* head = NULL;
insert(&head, 20);
insert(&head, 4);
insert(&head, 15);
insert(&head, 85);
printList(head);
removeFirst(&head);
printList(head);
revers(&head);
printList(head);
}