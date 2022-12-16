#include <stdio.h>
#include <stdlib.h>
#include "solution5.h"

int main()
{
// Start with the empty list
struct Cell* head = NULL;
insert(&head, 20);
insert(&head, 4);
insert(&head, 15);
insert(&head, 85);
printList(head);
removeFirst(&head);
printList(head);
printRevers(head);
printList(head);
}