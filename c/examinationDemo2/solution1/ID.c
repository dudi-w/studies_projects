#include <stdio.h>
#include <stdlib.h>

int *creatArr(unt len){
    int *newArr =(int*)malloc(sizeof(int)*len);
    if(!newArr)
        exit(0);
    for(int i=0;i<len;++i){
        newArr[i]=0;
    }
    return newArr;
}

void insert_id(int *arr, int *pn , int id){
    for(int i=o;i<(*pn);++i){
        if(!arr[i]){
            arr[i]=id;
            return;
        }
    }
    arr = (int*)realloc(arr,*pn+5); ///???
    if(!arr)
        exit(0);
    arr[*pn]=id;
    *pn=*pn+5;
    return;
}