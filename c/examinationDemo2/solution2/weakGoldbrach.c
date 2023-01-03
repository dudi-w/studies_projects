#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "solution2.h"

void findPrimes(int *arr, int num){
    int miss = num -3;
    for(int i=2;i<num;++i){
        if(isPrime(miss-i) && isPrime(i)){
            arr[0]=3;
            arr[1]=(int)miss-i;
            arr[2]=i;
            return;
        }
    }
    arr[0]=0;
    arr[1]=0;
    arr[2]=0;
    return;
}
    
    
    /*int end=0;
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
    }*/

bool isPrime(int num){
    for(int i=2;i< num;++i){
        if(num%i==0)
            return false;
    }
    return true;
}
void printArr(int *arr, int size){
    for(int i=0; i<size; ++i){
       printf("%d,", arr[i]);
    }
    printf("\n");
}

/*int *creatArrPrimes(int n){
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
}*/