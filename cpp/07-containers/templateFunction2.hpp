#ifndef TEMPL2_HPP
#define TEMPL2_HPP

#include <cstdlib>
#include <optional>
#include <array>

namespace tf
{

template <typename T>
std::optional<size_t*> getDuplicates(const std::array<T,0>& arr);

template <typename T>
bool isSorted(const T* pArr ,size_t  size);

template<typename Container>
typename Container::const_iterator getFirstUniq(Container const& container);

template<typename Container>
typename Container::const_iterator getFirstDuplicates(Container const& container);

}//namespace tm

#include "templateFunction2.inl"

#endif