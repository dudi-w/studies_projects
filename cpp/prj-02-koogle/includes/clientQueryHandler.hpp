#ifndef CLIENT_QUERY_HANDLER
#define CLIENT_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "getDatabase.hpp"

namespace se{//Search Engine

class ClientQueryHandler : public SearchQueryHandler
{
public:
    ClientQueryHandler();
    ClientQueryHandler(ClientQueryHandler const& other) = default;
    ClientQueryHandler& operator=(ClientQueryHandler const& other) = default;
    virtual ~ClientQueryHandler() = default;

    virtual void receivesRequest(se::Request& request, size_t resultCount = 10) override;
    virtual se::Result returnResult() override;

public:
    // linkVec m_VecResult;
    se::Result m_result;
};

}//namespace se

#endif