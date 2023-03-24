#ifndef MY_EXCEPTIONS_HPP
#define MY_EXCEPTIONS_HPP

#include <stdexcept>
#include <exception>

namespace se{

class InValidSrcURL : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class LaodJsonError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CommunicationError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

}//namespace es

#endif