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

class CreateSocketError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

class BindingSocketError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

class listenError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

class acceptError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

class readError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

class writeError : public se::CommunicationError
{
public:
    using se::CommunicationError::CommunicationError;
};

}//namespace es

#endif