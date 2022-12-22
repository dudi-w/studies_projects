#include <stdio.h>
#include <stdlib.h>

//int * mergeSort(int *arr1 ,int size1 ,int *arr2 , int size2);
//int *sort(int arr[], int start, int end);
int* partition(int arr[], int start, int end);
void printArray(int *arr, int size);
int inverse(int a);
int normal(int a);
int * mergeSort(int *arr1 ,int size1 ,int *arr2 , int size2, int (*fanc)(int));
int *sort(int arr[], int start, int end,int (*fanc)(int));