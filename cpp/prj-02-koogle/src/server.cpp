#include "server.hpp"

se::Server::Server(se::SearchQueryHandler& queryHandler, se::TextUI& tui )
: m_queryHandler(queryHandler)
, m_tui(tui)
{}

void se::Server::strart() const
{
    while(true){
        auto request = m_tui.makeRequest();
        if(request == nullptr){ break; }
        m_queryHandler.receivesRequest(*request, 10);
        auto result = m_queryHandler.returnResult();
        m_tui.setAndShowResult(result);
    }
}
