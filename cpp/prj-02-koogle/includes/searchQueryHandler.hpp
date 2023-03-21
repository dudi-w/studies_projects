#ifndef SEARCH_QUERY_HANDLER
#define SEARCH_QUERY_HANDLER

#include <algorithm>
#include <memory>

#include "searchDatabase.hpp"
#include "request.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"

namespace se{//Search Engine

class SearchQueryHandler
{
public:
    explicit SearchQueryHandler(SearchDB const& searchDB);
    SearchQueryHandler(SearchQueryHandler const& other) = default;
    SearchQueryHandler& operator=(SearchQueryHandler const& other) = default;
    ~SearchQueryHandler() = default;

    void receivesRequest(se::Request& request);
    std::unique_ptr<se::ResultIF> returnResult();
    std::vector<std::pair<std::string, size_t>> stripConst(std::vector<std::pair<const std::string, size_t>>& vecResult);

private:
    SearchDB const& m_SearchDB;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::ResultIF> m_ptrResult;
};

}//namespace se

#endif
