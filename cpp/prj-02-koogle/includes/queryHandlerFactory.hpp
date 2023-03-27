#ifndef QUERY_HANDLER_FACTORY_HPP
#define QUERY_HANDLER_FACTORY_HPP

#include "smartQueryHandler.hpp"
#include "simpleQueryHandler.hpp"
#include "multiQueryHandler.hpp"


namespace se{

class QueryHandlerFactory
{
public:
    QueryHandlerFactory() = default;
    QueryHandlerFactory(QueryHandlerFactory const& other) = default;
    QueryHandlerFactory& operator=(QueryHandlerFactory const& other) = default;
    ~QueryHandlerFactory() = default;

private:
    se::SimpleQueryHandler m_simpleQueryHandler;
    se::MultiQueryHandler m_multiQueryHandler;
    se::SmartQueryHandler m_smartQueryHandler;
};

}

#endif
