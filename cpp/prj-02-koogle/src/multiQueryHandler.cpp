#include <algorithm>

#include "multiQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"
#include "myExceptions.hpp"

se::MultiQueryHandler::MultiQueryHandler(se::GetDB const& searchDB)
: m_simpleQueryHandler(searchDB)
, m_result({})
{}

void se::MultiQueryHandler::receivesRequest(se::Request& request, size_t resultCount = 10)
{
    receivesRequest(request.getRequest(), resultCount);
}

void se::MultiQueryHandler::receivesRequest(std::vector<std::string> const& requests, size_t resultCount = 10)
{
    reset();
    m_requests = requests;
    if(m_requests.size() == 0){
        return;
    }
    auto lambdaNeg = [](std::string const& request){return request[0] == '-';};
    auto lambdaPos = [](std::string const& request){return request[0] != '-';};
    if(std::all_of(m_requests.cend(), m_requests.cend(), lambdaNeg)){
        makeForNegative();
    }else if(std::all_of(m_requests.cend(), m_requests.cend(), lambdaPos)){
        makeForPositive();
    }else{
        throw se::InValidArg("Mixed arguments!");
    }
    sortResult(resultCount);
}

void se::MultiQueryHandler::reset()
{
    m_requests.clear();
    m_result = se::Result({});
}

void se::MultiQueryHandler::makeForNegative()
{
    for(size_t i = 0; i < m_requests.size(); ++i){
        std::cout<<"m_requests[i].substr(1)"<<m_requests[i].substr(1)<<std::endl;
        m_simpleQueryHandler.receivesRequest(m_requests[i].substr(1), __INT32_MAX__);///???
        auto result = m_simpleQueryHandler.returnResult();
        if(result.getResult().size() != 0){
            m_result = m_result | result;
        }
    }
}

void se::MultiQueryHandler::makeForPositive()
{
    std::cout<<"makeForPositive = "<<m_requests[0].substr(1)<<std::endl;
    m_simpleQueryHandler.receivesRequest(m_requests[0], __INT32_MAX__);//max
    auto result = m_simpleQueryHandler.returnResult();
    if(result.getResult().size() == 0){
        return;
    }

    m_result = se::Result(result.getResult());

    for(size_t i = 1; i < m_requests.size(); ++i){
        std::cout<<"makeForPositive = "<<m_requests[i].substr(1)<<std::endl;
        m_simpleQueryHandler.receivesRequest(m_requests[i],__INT32_MAX__);///max
        result = m_simpleQueryHandler.returnResult();
        if(result.getResult().size() == 0){
            m_result = se::Result({});
            return;
        }
        m_result = m_result & result;
    }
}

void se::MultiQueryHandler::sortResult(size_t resultCount)
{
    std::vector<std::pair<std::string, size_t>> vecResult;
    for(auto const& pair : m_result.getResult()){
        vecResult.push_back(pair);
    }
    auto lambda = [](auto pair1 ,auto pair2){return pair1.second > pair2.second;};
    std::sort(vecResult.begin(), vecResult.end(), lambda);

    auto it = vecResult.begin();
    for(size_t i = 0 ; i < resultCount && it != vecResult.end(); ++i){
        ++it;
    }
    m_result = se::Result(vecResult.begin(), it);
}

se::Result se::MultiQueryHandler::returnResult()
{
    return m_result;
}
