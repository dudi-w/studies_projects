#ifndef SMART_QUERY_HANDLER
#define SMART_QUERY_HANDLER

#include <algorithm>

#include "getDatabase.hpp"
#include "searchQueryHandler.hpp"
#include "multiQueryHandler.hpp"

namespace se{//Search Engine

class SmartQueryHandler : public SearchQueryHandler
{
public:
    explicit SmartQueryHandler(se::GetDB const& searchDB);
    SmartQueryHandler(SmartQueryHandler const& other) = default;
    SmartQueryHandler& operator=(SmartQueryHandler const& other) = default;
    virtual ~SmartQueryHandler() = default;

    virtual void receivesRequest(se::Request& request, size_t resultCount = 10) override;
    virtual std::unique_ptr<se::Result> returnResult() override;

private:
    se::NMultiQueryHandler m_NMultiQueryHandler;
    se::PMultiQueryHandler m_PMultiQueryHandler;
    std::vector<std::string> m_requests;
    std::vector<std::string> m_negativeRequests;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::Result> m_ptrResult;
};

}//namespace se

#endif
