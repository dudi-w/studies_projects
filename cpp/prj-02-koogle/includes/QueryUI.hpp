#ifndef QUERYS_IF_HPP
#define QUERYS_IF_HPP

#include <memory>

#include "simpleRequest.hpp"
#include "result.hpp"

namespace se{//Search Engin

class QueryBuilder//?QuerysIF
{
public:
    virtual ~QueryBuilder() = default;

    virtual std::unique_ptr<se::Request> makeRequest() = 0;
    virtual void recieveResult(se::Result& result) const = 0;//? recieveResult??
};

}

#endif

