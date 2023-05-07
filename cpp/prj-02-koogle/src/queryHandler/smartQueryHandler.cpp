#include <limits>

#include "smartQueryHandler.hpp"
#include "request.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::SmartQueryHandler::SmartQueryHandler(se::GetDB const& searchDB)
: m_multiQueryHandler(searchDB)
, m_result({})
{}

void se::SmartQueryHandler::reset()
{
    m_requests.clear();
    m_negativeRequests.clear();
    m_result = se::Result({});
}

void se::SmartQueryHandler::receivesRequest(se::RequestIF& request)
{
    reset();
    std::vector<std::string> new_requests = request.getRequest();
    if(new_requests.size() == 0){
        return;
    }

    for(auto& request : new_requests){
        auto startsWith = [](std::string const &s, std::string const &w){return !s.compare(0, w.size(), w);};
        if(startsWith(request,"-")){
            m_negativeRequests.push_back(request);
        }else{
            m_requests.push_back(request);
        }
    }
    if(m_requests.size() == 0 && m_negativeRequests.size() > 0){
        return;
    }

    m_multiQueryHandler.receivesRequest(m_requests);
    auto P_Result = m_multiQueryHandler.returnResult();
    if(P_Result.getResult().size() == 0){
        return;
    }
    m_result = se::Result(P_Result);

    m_multiQueryHandler.receivesRequest(m_negativeRequests);
    auto N_Result = m_multiQueryHandler.returnResult();
    if(N_Result.getResult().size() != 0){
        m_result = m_result - N_Result;
    }
    if(m_result.getResult().size() == 0){
        return;
    }
    sortResult();
}

void se::SmartQueryHandler::sortResult()
{
    LinkVec vecResult;
    for(auto const& pair : m_result.getResult()){
        vecResult.push_back(pair);
    }
    auto lambda = [](auto pair1 ,auto pair2){return pair1.second > pair2.second;};
    std::sort(vecResult.begin(), vecResult.end(), lambda);
    m_result = std::move(se::Result(vecResult));
}

se::Result se::SmartQueryHandler::returnResult()
{
    return m_result;
}