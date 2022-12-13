#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "solution6.h"

int main(){
    srand(time(NULL));
    int arr2[] = {-7,-10,1,2,3,4,5,6,7,8};
    int arr3[] = {36 ,1,-18,6,9,1,3,5,1,0};
    int *arr = creatFillArray();
    int *result = findMaximumProduct(arr);
    findArrayDelimiter(arr);

    /***********************/
    for(int i= 0; i< SIZE ; ++i)
        printf("%d, " , arr[i]);
    printf("\n");
    printf("%d, %d\n", result[0] , result[1]);

    /***********************/
    free(arr);
    free(result);
    
    

    return 0;
}