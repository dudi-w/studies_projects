#ifndef MULTI_QUERY_HANDLER
#define MULTI_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "simpleQueryHandler.hpp"

namespace se{//Search Engine

class MultiQueryHandler : public SearchQueryHandler
{
public:
    explicit MultiQueryHandler(SearchDB const& searchDB);
    MultiQueryHandler(MultiQueryHandler const& other) = default;
    MultiQueryHandler& operator=(MultiQueryHandler const& other) = default;
    virtual ~MultiQueryHandler() = default;

    virtual void receivesRequest(se::Request& request) override;
    virtual std::unique_ptr<se::ResultIF> returnResult() override;

private:
    bool checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link);

private:
    SearchDB const& m_SearchDB;
    std::vector<std::string> m_requests;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::ResultIF> m_ptrResult;
};

}//namespace se

#endif
