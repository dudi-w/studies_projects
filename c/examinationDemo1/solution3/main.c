#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution3.h"

int main(){
    char *word= "yolo";
    char *a = "only";
    char *b= "you";
    char *c= "live";
    char *d= "once";
    char *arr[] ={c,d, a,b};
    char **p_arr = arr;
    printArrString(p_arr);
    sortSringsByMatch(p_arr ,4,word);
    printArrString(p_arr);
    return 0;
}