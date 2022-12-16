typedef struct cell Cell;
typedef struct cell {
    int data;
    Cell * next;
    Cell * prev;
} Cell;

void insert(Cell** head_ref, int new_data);
int removeFirst( Cell** head_ref);
void printList(Cell* head);
void printRevers(Cell * head);