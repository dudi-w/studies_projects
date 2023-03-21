#ifndef MY_EXCEPTIONS_HPP
#define MY_EXCEPTIONS_HPP

#include <curlpp/Exception.hpp>
#include <stdexcept>
#include <exception>

namespace es{

class inValidURL : public curlpp::UnsetOption
{

public:
    using curlpp::UnsetOption::UnsetOption;
};

class LaodJsonError : public std::runtime_error
{

public:
    using std::runtime_error::runtime_error;
};

}//namespace es

#endif
