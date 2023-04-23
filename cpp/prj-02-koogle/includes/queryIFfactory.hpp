#ifndef QUERY_FACTORY_HPP
#define QUERY_FACTORY_HPP

#include <memory>

#include "QueryUI.hpp"
#include "textUI.hpp"
#include "TCPqueryIF.hpp"

namespace se{//Search Engine

class QueryIFfactory//?QueryIFfactory
{
public:
    QueryIFfactory() = default;
    QueryIFfactory(QueryIFfactory const& other) = default;
    QueryIFfactory& operator=(QueryIFfactory const& other) = default;
    ~QueryIFfactory() = default;

    se::QueryBuilder& getIF();

private:
    std::unique_ptr<se::QueryBuilder> m_query;
};

}//namespace se

#endif
