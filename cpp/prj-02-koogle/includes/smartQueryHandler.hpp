#ifndef SMART_QUERY_HANDLER
#define SMART_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "multiQueryHandler.hpp"

namespace se{//Search Engine

class SmartQueryHandler : public SearchQueryHandler
{
public:
    explicit SmartQueryHandler(SearchDB const& searchDB);
    SmartQueryHandler(SmartQueryHandler const& other) = default;
    SmartQueryHandler& operator=(SmartQueryHandler const& other) = default;
    virtual ~SmartQueryHandler() = default;

    virtual void receivesRequest(se::Request& request) override;
    virtual std::unique_ptr<se::ResultIF> returnResult() override;

private:
    bool checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link);
    bool checkLinkMotExistsInWrds(std::vector<std::string> const& words, std::string const& link);

private:
    SearchDB const& m_SearchDB;
    std::vector<std::string> m_requests;
    std::vector<std::string> m_negativeRequests;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::ResultIF> m_ptrResult;
};

}//namespace se

#endif
