#ifndef QUERY_FACTORY_HPP
#define QUERY_FACTORY_HPP

#include "QueryUI.hpp"
#include "textUI.hpp"

namespace se{//Search Engine

class QueryIFfactory
{
public:
    QueryIFfactory() = default;
    QueryIFfactory(QueryIFfactory const& other) = default;
    QueryIFfactory& operator=(QueryIFfactory const& other) = default;
    ~QueryIFfactory() = default;

    se::QuerysIF& getIF();
private:
    se::TextUI m_tui;
};

}//namespace se

#endif
