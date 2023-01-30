#ifndef TEMPL_HPP
#define TEMPL_HPP

#include <cstdlib>

namespace tf
{

template <typename T>
__int128_t getUniqueIndex(const T* pArr ,size_t  size);

template <typename T>
size_t getUniqueIndex2(const T* pArr ,size_t  size);

template <typename T>
T& getMinMember(T* pArr ,size_t  size);

}//namespace tm

#include "templateFunction.inl"

#endif
