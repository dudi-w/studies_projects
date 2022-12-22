#include <stdio.h>
#include <stdlib.h>
#include "solution1.h"

int * mergeSort(int *arr1 ,int size1 ,int *arr2 , int size2, int (*func)(int)){

    if(size1<1)
        return arr2;
    if(size2<1)
        return arr1;
    int *arr = malloc(sizeof(int)*(size1+size2));
    int j ,k;
    j=k=0;

    for(int i=0; i< size1+size2 ;++i){
        printf("arr1[%d] = %d ---  arr2[%d] = %d\n", j ,arr1[j], k, arr2[k]);
        if((func(arr1[j])<=func( arr2[k]) && j<size1) || k>=size2 )
            arr[i]=arr1[j++];
        else
            arr[i]=arr2[k++];
    }
    printArray(arr, size1+size2);
    return arr;

}

int *sort(int arr[], int start, int end,int (*func)(int)){
    if(end-start<=1)
        return arr;
    int *arr1 = partition(arr ,start, (end-start)/2);
    int *arr2 = partition(arr ,((end-start)/2), end+1 );
    int size1= ((end-start)/2)-start;
    int size2= end-(((end-start)/2));
    printArray(arr1,size1);
    printArray(arr2,size2);
    printf("size1 = %d\t size2 = %d\n",size1,size2);
    if (size1 >1)
        arr1 = sort(arr1 ,start, (end-start)/2, func);
    if(size2>1)
        arr2 = sort(arr2,0, size2, func);
    int *sortArr = mergeSort(arr1 ,size1 , arr2 , size2, func);
    free(arr1);
    free(arr2);
    return sortArr;
}

int* partition(int arr[], int start, int end){
    if(start>= end-1)
        return arr;
    int size =end-start;
    int *subArr1 = malloc(sizeof(int)*size);
    for(int i = 0 ; i <size ;++i)
        subArr1[i]= arr[i+start];
    return subArr1;
}

int inverse(int a){
    return -1*a;
}

int normal(int a){
    return a;
}


void printArray(int *arr, int size){
    for(int i=0; i<size; ++i)
        printf("%d, ",arr[i]);
    printf("\n");
}
