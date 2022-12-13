#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "solution6.h"

int *creatFillArray(){
    int *array = malloc(sizeof(int)*SIZE);
    for(int i=0; i<SIZE; ++i){
        *(array+i) = (rand()%100)-50;
        }
    return array;
}

int findArrayDelimiter(int arr[]){
    int sumEnd ,sumStert;
    sumEnd = sumStert = 0;
    
    for(int i=1; i<SIZE; ++i)
        sumEnd+= *(arr+i);
    
    for(int i =0 ; i< SIZE ; ++i){
        if(sumEnd == sumStert){
            printf("The delimiter value is %d and it is at index %d\n" ,arr[i] ,i);
            return 0;
        }
        sumStert += arr[i];
        sumEnd -= arr[i+1];
    }
    printf("The task is not possible for this order of the array\n");
    return 0;
}