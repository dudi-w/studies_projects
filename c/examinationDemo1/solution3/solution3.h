#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(char **a, char **b);
void printArrString(char** arrString);
bool lookFor(char* str, char w, int buffer);
char* uniqChar(char *str);
int scor(char *word , char* str);
void sortSringsByMatch(char** arr ,int arrSize ,char * word);