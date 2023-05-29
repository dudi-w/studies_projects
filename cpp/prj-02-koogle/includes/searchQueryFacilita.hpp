#ifndef QUERYFACILITA_HPP
#define QUERYFACILITA_HPP

#include "searchQueryHandler.hpp"
#include "queryBuilderIF.hpp"

namespace se{//Search Engine

class SearchQueryFacilita
{
public:           
    explicit SearchQueryFacilita(se::SearchQueryHandler& queryHandler, se::QueryBuilder& queryIF );
    SearchQueryFacilita(SearchQueryFacilita const& other) = default;
    SearchQueryFacilita& operator=(SearchQueryFacilita const& other) = default;
    ~SearchQueryFacilita() = default;

    void start() const;

private:
    se::SearchQueryHandler& m_queryHandler;
    se::QueryBuilder& m_queryIF;
};

}//namespace se

#endif
