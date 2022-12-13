#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "solution6.h"


int* findMaximumProduct(int arr[]){
    int max1 ,max2 ,min1 ,min2 ,indexMax1 ,indexMin1;
    max1= max2 = min1 = min2= arr[0];
    indexMax1 = indexMin1 = 0;

    for(int i=1 ; i< SIZE ; ++i){
        if(arr[i]<min1){
            min1 =arr[i];
            indexMin1 =i;
        }
        if(arr[i]<min2 && i!= indexMin1)
            min2= arr[i];
        
        if(arr[i]>max1){
            max1 =arr[i];
            indexMax1 =i;
        }
        if(arr[i]>max2 && i!= indexMax1)
            max2= arr[i];
    }

    int *result = malloc(sizeof(int)*2);

   // result[0] = (max1*max2 > min1*min2)?max1:min1;

    if(max1*max2 > min1*min2){
        result[0]= max1;
        result[1]= max2;
    }
    else{
        result[0]= min1;
        result[1]= min2;
    }
    return result;

}