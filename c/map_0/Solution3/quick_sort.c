#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3000
#define MAX 1000000
int array[SIZE];

void printArray();
void init();
int partition( int arr[], int len , int axisNember );
void quickSort(int arr[], int size);

int main()
{
    srand(time(NULL));
    init();
    printArray();
    quickSort(array , SIZE);
    printArray();
    return 0;
}

void init() {
    int i;
    for(i=0; i<SIZE; ++i)
        array[i] = random()%MAX;
}

void printArray() {
    int i;
    for(i=0; i<SIZE; ++i)
        printf("%d, ",array[i]);
    printf("\n");
    
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition( int arr[], int len , int axisNember ){
    int pointer=0;
    swap(&arr[0], &arr[axisNember]);
    for(int i=1 ; i<len ; i++){
        if (arr[i] < arr[0]){
            pointer++;
            swap(&arr[pointer], &arr[i]);
        }
    }
    swap(&arr[pointer], &arr[0]);
    return pointer;
}


void quickSort(int arr[], int size){
    if (size<=1)
        return;
    int pivot = random()%(size);
    //printf("%d -pivot-\t%d-value-\n", pivot ,arr[pivot]);
    int axisNember =partition( arr ,size ,pivot);
    quickSort(arr, axisNember);
    quickSort(arr+axisNember+1 ,size-axisNember-1);
    //printArray();
}