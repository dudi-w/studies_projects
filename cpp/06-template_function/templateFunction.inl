#ifndef TEMPL_INL
#define TEMPL_INL
#include "templateFunction.hpp"
#include <unordered_map>

template <typename T>
__int128_t tf::getUniqueIndex(const T* pArr , size_t  size)
{
    for(size_t i = 0 ; i <size ;++i){
        bool check = true;
        for(size_t j = 0 ; j <size && check ;++j){
            if(pArr[i]==pArr[j] && i!=j){
                check = false;
            }
            if(pArr[i]!=pArr[j] && j==size-1){
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
size_t tf::getUniqueIndex2(const T* pArr , size_t  size)
{
    std::unordered_map< T, int> map;
    for(size_t i = 0 ; i<size ; ++i){
        map[pArr[i]]= (!map[pArr[i]]) ? 1: map[pArr[i]]+=1;
    }
    for(size_t i =0 ; i<size ; ++i){
        if(map[pArr[i]]==1){
            return i;
        }
    }
    return -1;
}

template <typename T>
T& tf::getMinMember(T* pArr , size_t size)
{
    size_t IndexMin = 0;
    for(size_t i=1 ; i< size ; ++i){
        if(pArr[i]<pArr[IndexMin]){
            IndexMin = i;
        }
    }
    return pArr[IndexMin];
}

#endif