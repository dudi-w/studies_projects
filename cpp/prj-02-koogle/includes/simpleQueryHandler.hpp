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

    virtual void receivesRequest(se::Request& request, size_t resultCount = 10) override;
    virtual std::unique_ptr<se::Result> returnResult() override;

private:
    se::GetDB const& m_SearchDB;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::Result> m_ptrResult;
};

}//namespace se

#endif
