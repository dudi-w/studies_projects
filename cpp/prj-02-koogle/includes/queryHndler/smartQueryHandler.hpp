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
    virtual se::Result returnResult() override;

private:
    void reset();
    void sortResult(size_t resultCount = 10);

private:
    se::MultiQueryHandler m_multiQueryHandler;
    std::vector<std::string> m_requests;
    std::vector<std::string> m_negativeRequests;
    linkVec m_vetResult;
    se::Result m_result;
};

}//namespace se

#endif
