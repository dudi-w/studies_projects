#ifndef SERVER_HPP
#define SERVER_HPP

#include "searchQueryHandler.hpp"
#include "textUI.hpp"

namespace se{//Search Engine

class Server
{
public:
    explicit Server(se::SearchQueryHandler& queryHandler, se::QuerysIF& tui );
    Server(Server const& other) = default;
    Server& operator=(Server const& other) = default;
    ~Server() = default;

    void strart() const;

private:
    se::SearchQueryHandler& m_queryHandler;
    se::QuerysIF& m_tui;
};

}//namespace se

#endif
