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

class InValidArg : public std::logic_error
{
public:
    using std::logic_error::logic_error;
};

class StorageError : public std::logic_error
{
public:
    using std::logic_error::logic_error;
};

class SearchError : public std::logic_error
{
public:
    using std::logic_error::logic_error;
};

class communicationError : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class CreateSocketError : public se::communicationError
{
public:
    using se::communicationError::communicationError;
};

class BindingSocketError : public se::communicationError
{
public:
    using se::communicationError::communicationError;
};

}//namespace es

#endif