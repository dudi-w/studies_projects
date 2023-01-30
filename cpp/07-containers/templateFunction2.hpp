#ifndef TEMPL2_HPP
#define TEMPL2_HPP

#include <cstdlib>

namespace tf
{

template <typename T>
size_t* getDuplicates(const T pArr[] ,size_t  size);

template <typename T>
bool isSorted(const T pArr[] ,size_t  size);

}//namespace tm

#include "templateFunction2.inl"

#endif