#ifndef QUERYFACILITA_HPP
#define QUERYFACILITA_HPP

#include "searchQueryHandler.hpp"
#include "QueryUI.hpp"

namespace se{//Search Engine

class SearchQueryFacilita
{
public:           
    explicit SearchQueryFacilita(se::SearchQueryHandler& queryHandler, se::QuerysIF& queryIF );
    SearchQueryFacilita(SearchQueryFacilita const& other) = default;
    SearchQueryFacilita& operator=(SearchQueryFacilita const& other) = default;
    ~SearchQueryFacilita() = default;

    void strart() const;

private:
    se::SearchQueryHandler& m_queryHandler;
    se::QuerysIF& m_queryIF;
};

}//namespace se

#endif
