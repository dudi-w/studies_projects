#include <unordered_map>
#include "templateFunction2.hpp"

template <typename T>
size_t* tf::getDuplicates(const T arr[] ,size_t  size)
{
    std::unordered_map <T,size_t> map;
    for(size_t i = 0 ; i <size ; ++i){
        
        if(map.count(arr[i])==0){
            map[arr[i]]=i;
        }
        else{
            size_t* arrResulte = new size_t[2];
            arrResulte[0] = map.at(arr[i]);
            arrResulte[1] = i;
            return arrResulte;
        }
        std::cout <<'\n';
    }
    return NULL;
}

template <typename T>
bool tf::isSorted(const T arr[] ,size_t  size)
{
    for(size_t i= 1; i <size ; ++i){
        if(arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}