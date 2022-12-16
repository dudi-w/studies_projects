#include <stdio.h>
#include <stdlib.h>

typedef struct Node  Node;

Node* newNode(int data);
void insert(Node **root, int data);
int treeHeight(Node *root);
int numOfNodes(Node *root);
void printTreeRec(Node *root);
void printTree(Node *root);
void freeTree(Node *root);
int isIn(Node *root, int data);