#include <stdio.h>
#include <stdlib.h>


int binarySearch(int *arr, int head, int end, int num){
    int size = end-head;
    printf("arr[%d]=%d  ?==? %d ... head=%d, end=%d \n", head+size/2,arr[head+size/2], num, head, end);
    if(size<=1)
        return head;
    if(arr[head+size/2]==num)
        return head+size/2;
    if(arr[head+size/2]<num)
       return binarySearch(arr,head+size/2, end ,num);
    return binarySearch(arr,head,head+size/2, num);

int main(){
    int arr[]={0,1,2,3,5,6,7,9,10,150,200};
    printf("%d\n", binarySearch(arr,0,11,500));
    return 0;
}