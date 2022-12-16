#include <stdio.h>
#include <stdlib.h>
#include "solution3.h"

typedef struct Node {
int data;
struct Node *ls, *rs;
} Node;

Node* newNode(int data) {
Node *p = (Node*) malloc (sizeof(Node));
p->data = data;
p->ls = p->rs = NULL;
return p;
}
void insert(Node **root, int data) {
    if((*root)==NULL){
        (*root)= newNode(data);
        return;
    }
    if((*root)->data > data)
        insert((&(*root)->ls), data);
    else{
        insert((&(*root)->rs), data);
    }
}
int treeHeight(Node *root) {
    if (root==NULL) 
        return -1;
    return treeHeight(root->ls) > treeHeight(root->rs)?treeHeight(root->ls)+1 : treeHeight(root->rs)+1;
}
int numOfNodes(Node *root) {
     if (root==NULL) 
        return 0;
    return numOfNodes(root->ls) + numOfNodes(root->rs)+1;
}
void printTreeRec(Node *root) {
    printf("%d" , root->data);
}
void printTree(Node *root) {
    if (root==NULL) 
        return;
    printTree(root->ls);
    printTreeRec(root);
    printTree(root->rs);
}
void freeTree(Node *root) {
    if (root==NULL) 
        return;
    freeTree(root->ls);
    freeTree(root->rs);
    free(root);
}
int isIn(Node *root, int data){
    if (root==NULL) 
        return 0;
    if(root->data==data)
        return 1;
    else if (root->data > data){
        return isIn(root->ls , data);
    return isIn(root->rs , data);
    }
}