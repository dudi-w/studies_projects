#ifndef TEMPL2_HPP
#define TEMPL2_HPP

#include <cstdlib>
#include <optional>
#include <array>
#include <functional>

namespace tf
{

template <typename T>
std::optional<size_t*> getDuplicates(const std::array<T,0>& arr);

template <typename T>
bool isSorted(const T* pArr ,size_t  size);

template<typename Container>
typename Container::const_iterator getFirstUniq(Container const& container);

template<typename Iterator>
typename Iterator::value_type sumRange(Iterator begin ,Iterator end, std::function<typename Iterator::value_type(Iterator&)> fun);

template<typename Container>
typename Container::const_iterator getFirstDuplicates(Container const& container);

template <typename Iterator>
Iterator tf::find(Iterator begin ,Iterator end, typename Iterator::value_type v)

}//namespace tm

#include "templateFunction2.inl"

#endif