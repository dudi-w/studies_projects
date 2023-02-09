#include <unordered_map>
#include "templateFunction2.hpp"

template <typename T>
std::optional<size_t*> tf::getDuplicates(const std::array<T,7>& arr)
{
    std::unordered_map <T,size_t> map;
    for(size_t i = 0 ; i <arr.size() ; ++i){
        
        if(map.count(arr[i])==0){
            map[arr[i]]=i;
        }
        else{
            size_t* arrResulte = new size_t[2];
            arrResulte[0] = map.at(arr.at(i));
            arrResulte[1] = i;
            return arrResulte;
        }
    }
    return {};
}

template <typename T>
bool tf::isSorted(const T* arr ,size_t  size)
{
    if(arr == nullptr){
        return true;
    }

    bool checkSort = true;
    bool checkSortRev = true;
    for(size_t i = 1; i < size ; ++i){
        if(arr[i-1] > arr[i]){
            checkSort = false;
        }
        if(arr[i-1] < arr[i]){
            checkSortRev = false;
        }
    }
    return (checkSortRev || checkSort);
}

template<typename Container>
typename Container::const_iterator  tf::getFirstUniq(Container const& container)
{
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator end = container.end();
    std::unordered_map <typename Container::value_type, size_t> map;

    while(it != end){
        ++map[*it];
        ++it;
    }

    it = container.begin();
    while(it != end){
        if(map[*it]==1){
            return it;
        }
        ++it;
    }
    return end;
}

template<typename Container>
typename Container::const_iterator  tf::getFirstDuplicates(Container const& container)
{
    using iter = typename Container::const_iterator;
    iter it = container.cbegin();
    iter end = container.cend();
    std::unordered_map <typename Container::value_type, iter > map;
        while(it != end){
            
            if(map.count(*it)==0){
                map[*it]=it;
                ++it;
            }
            else{
                it = map.at(*it);
                return it;
            }
        }
        return end;
}
