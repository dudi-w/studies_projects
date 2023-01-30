#include <iostream>
#include "templateFunction2.hpp"

int main()
{
    int arr[7]={5,2,17,7,52,20,7};
    size_t* resulteArr = tf::getDuplicates(arr, 7);
    std::cout<<resulteArr[0] <<'\t' << resulteArr[1] <<'\n';
    std::cout<<tf::isSorted(arr, 7)<<'\n';
    
    if(resulteArr!=NULL){
        delete[] resulteArr;
    }
    return 0;
}