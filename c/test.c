#include <stdio.h>
void zeero(int *arr, int size)
{
    for(int i=0; i<size; ++i)
        arr[i]=0;
}

void printarr(int *arr, int size){
    for(int i=0; i<size; ++i)
        printf("%d,", arr[i]);
    printf("\n");
}

void creatArr(){
    int n;
    scanf("%d" ,&n);
    int arr[n];
    for(int i=0; i<n;++i)
        arr[i]=i;
    printarr(arr, n);
}

int main()
{
    int arr[]= {1,2,3,4,5};
    printarr(arr,5);
    zeero(arr,5);
    printarr(arr,5);
    creatArr();
    return 0;
}
