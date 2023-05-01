#ifndef QUERY_FACTORY_HPP
#define QUERY_FACTORY_HPP

#include <memory>

#include "QueryBuilderIF.hpp"
#include "textUI.hpp"
#include "TCPqueryIF.hpp"

namespace se{//Search Engine

class QueryBuilderFactory
{
public:
    QueryBuilderFactory() = default;
    QueryBuilderFactory(QueryBuilderFactory const& other) = default;
    QueryBuilderFactory& operator=(QueryBuilderFactory const& other) = default;
    ~QueryBuilderFactory() = default;

    se::QueryBuilder& getQueryBuilder();

private:
    std::unique_ptr<se::QueryBuilder> m_query;
};

}//namespace se

#endif
