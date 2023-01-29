#include <iostream>
#include "templateFunction.hpp"

int main()
{
    int arr[7]={5,2,59,5,2, 59 ,2};
    std::cout<<(int)tf::getUniqueIndex(arr, 7)<<'\n';
    std::cout<<tf::getMinMember(arr, 7)<<'\n';
    return 0;
}
