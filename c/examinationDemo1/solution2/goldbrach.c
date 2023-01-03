#include <stdio.h>
#include <stdlib.h>
#include "solution2.h"

void findPrimes(int *arr, int len, int num, int* n1 ,int *n2){
    int end=0;
    while (arr[end]<num)
        ++end;
    for(int i=0;i<end;){
        printf("i = %d\tarr[i]=%d\tend= %d\tarr[end] = %d\n",i,arr[i],end,arr[end]);
        if(arr[i]+arr[end-1]==num){
            *n1=arr[i];
            *n2=arr[end];
            return;
        }
        else if(arr[i]+arr[end]>num)
                --end;
            else
                ++i;
    }
}

void printarr(int *arr, int size){
    for(int i=0; i<size; ++i){
       printf("%d,", arr[i]);
    }
    printf("\n");
}

int *creatArrPrimes(int n){
    int *arr=(int*)malloc(sizeof(int)*n);
    for(int i=2;i<n;++i){
        arr[i]=i;
    }
    int count=0;
    for(int i=2;i<n;++i){
        if(!arr[i])
            continue;
        ++count;
        for(int j=i*2;j<n;j+=i)
            arr[j]=0;
    }
    printf("%d\n",count);
    //printarr(arr,n);
    int *arrPrimes=(int*)malloc(sizeof(int)*count);
    int j=0;
    for(int i=0; i<n,j<count;++i)
        if(arr[i]){
            arrPrimes[j++]=arr[i];
        }
    //printarr(arrPrimes, count);
    free(arr);
    return arrPrimes;
}