#ifndef SIMPLE_QUERY_HANDLER
#define SIMPLE_QUERY_HANDLER

#include "searchQueryHandler.hpp"

namespace se{//Search Engine

class SimpleQueryHandler : public SearchQueryHandler
{
public:
    explicit SimpleQueryHandler(SearchDB const& searchDB);
    SimpleQueryHandler(SimpleQueryHandler const& other) = default;
    SimpleQueryHandler& operator=(SimpleQueryHandler const& other) = default;
    virtual ~SimpleQueryHandler() = default;

    virtual void receivesRequest(se::Request& request) override;
    virtual std::unique_ptr<se::ResultIF> returnResult() override;

private:
    SearchDB const& m_SearchDB;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::ResultIF> m_ptrResult;
};

}//namespace se

#endif
