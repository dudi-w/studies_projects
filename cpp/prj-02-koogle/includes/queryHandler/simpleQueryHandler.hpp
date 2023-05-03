#ifndef SIMPLE_QUERY_HANDLER
#define SIMPLE_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "getDatabase.hpp"

namespace se{//Search Engine

class SimpleQueryHandler : public SearchQueryHandler
{
public:
    explicit SimpleQueryHandler(se::GetDB const& searchDB);
    SimpleQueryHandler(SimpleQueryHandler const& other) = default;
    SimpleQueryHandler& operator=(SimpleQueryHandler const& other) = default;
    virtual ~SimpleQueryHandler() = default;

    virtual void receivesRequest(se::RequestIF& request, size_t resultCount = 10) override;
    void receivesRequest(std::string const& requests, size_t resultCount = 10);
    virtual se::Result returnResult() override;

private:
    se::GetDB const& m_SearchDB;
    LinkVec m_VecResult;
    se::Result m_result;
};

}//namespace se

#endif
