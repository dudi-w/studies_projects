#include <stdio.h>
#include "solution1.h"

int main(){
    int arr1[] = {16, 18, 58, 3, 90, 19, 31, 49, 12, 23, 6, -83, 79, 47, 25, 17, 18, 75, 82, 42, 58, 89, 45, 81, 79, 35, 94, 25, 42, 96, 3, 56, 13, 59, 57, 5, 79, 88, 52, 91, 10, 58, 76, 90, 4, 0, 6, 22, 73, 88};
    int arr2[] = {-4,-1,0,3};
    int arr3[50000];
    init(arr3, 50000);
    int *sotrarr= sort(arr3,0,50000,&normal);
    //int *sotrarrInverse= sort(arr3,0,50,&inverse);
    printArray(sotrarr, 50000);
    free(sotrarr);