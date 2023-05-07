#include "searchQueryFacilita.hpp"

#include <iostream>

se::SearchQueryFacilita::SearchQueryFacilita(se::SearchQueryHandler& queryHandler, se::QueryBuilder& queryIF )
: m_queryHandler(queryHandler)
, m_queryIF(queryIF)
{}

void se::SearchQueryFacilita::start() const
{
    while(true){
        auto request = m_queryIF.makeRequest();
        if(request == nullptr){
            break;
        }
        if(request->getRequest()[0] == "1234"){
            m_queryHandler.receivesRequest(*request);
            break;
        }
        m_queryHandler.receivesRequest(*request);   
        auto result = m_queryHandler.returnResult();
        m_queryIF.recieveResult(result);
    }
}
