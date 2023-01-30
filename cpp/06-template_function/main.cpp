#include <iostream>
#include "templateFunction.hpp"

int main()
{
    float arr[7]={5,2.6545,59,5,2.9, 8 ,52};
    std::cout<<(int)tf::getUniqueIndex2(arr, 7)<<'\n';
    std::cout<<tf::getMinMember(arr, 7)<<'\n';
    return 0;
}
