#ifndef TEMPL_INL
#define TEMPL_INL
#include "templateFunction.hpp"
#include <unordered_map>

template <typename T>
__int128_t tf::getUniqueIndex(const T* arr , size_t  size)
{
    for(size_t i = 0 ; i <size ;++i){
        bool check = true;
        for(size_t j = 0 ; j <size && check ;++j){
            if(arr[i]==arr[j] && i!=j){
                check = false;
            }
            if(arr[i]!=arr[j] && j==size-1){
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
size_t tf::getUniqueIndex2(const T* arr , size_t  size)
{
    std::unordered_map < T, size_t> map;
    map.get_allocator();
    for(size_t i = 0 ; i<size ; ++i){
        ++map[arr[i]];
    }
    for(size_t i =0 ; i<size ; ++i){
        if(map[arr[i]]==1){
            return i;
        }
    }
    return -1;
}

template <typename T>
T& tf::getMinMember(T* arr , size_t size)
{
    size_t IndexMin = 0;
    for(size_t i=1 ; i< size ; ++i){
        if(arr[i]<arr[IndexMin]){
            IndexMin = i;
        }
    }
    return arr[IndexMin];
}

#endif