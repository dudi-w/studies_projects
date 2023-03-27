#include "multiQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::PMultiQueryHandler::PMultiQueryHandler(se::GetDB const& searchDB)
: m_searchDB(searchDB)///???
, m_simpleQueryHandler(m_searchDB)
{}


void se::PMultiQueryHandler::receivesRequest(se::Request& request, size_t resultCount = 10)
{
    receivesRequest(request.getRequest(), resultCount);
}

void se::PMultiQueryHandler::receivesRequest(std::vector<std::string> const& requests, size_t resultCount = 10)
{
    m_requests.clear();
    m_result.clear();

    std::vector<std::string> new_requests = requests;
    if(new_requests.size() == 0){
        m_ptrResult = nullptr;
    }

    SimpleRequest simpleRequest(new_requests[0]);
    m_simpleQueryHandler.receivesRequest(simpleRequest, __INT32_MAX__);
    auto result = m_simpleQueryHandler.returnResult();
    if(result == nullptr){
        m_ptrResult = nullptr;
        return;
    }
    se::Result myResult(result->getResult());

    for(size_t i = 1 ; i<  new_requests.size() ; ++i){
        SimpleRequest simpleRequest(new_requests[i]);
        m_simpleQueryHandler.receivesRequest(simpleRequest,__INT32_MAX__);
        auto result = m_simpleQueryHandler.returnResult();
        if(result == nullptr){
            m_ptrResult = nullptr;
            return;
        }
        myResult = myResult & (*result);
    }

    for(auto const& pair : myResult.getResult()){
        m_result.push_back(pair);
    }
    auto lambda = [](auto pair1 ,auto pair2){return pair1.second > pair2.second;};
    std::sort(m_result.begin(), m_result.end(), lambda);

    auto it = m_result.begin();
    for(size_t i = 0 ; i < resultCount && it != m_result.end(); ++i){
        ++it;
    }
    m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
}

std::unique_ptr<se::Result> se::PMultiQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}

bool se::PMultiQueryHandler::checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link){
    for(size_t i = 0 ; i < words.size() ; ++i){
        if(!m_searchDB.wordAndLinkExis(words[i], link)){
            return false;
        }
    }
    return true;
}

se::NMultiQueryHandler::NMultiQueryHandler(se::GetDB const& searchDB)
: m_searchDB(searchDB)///???
, m_simpleQueryHandler(m_searchDB)
{}
void se::NMultiQueryHandler::receivesRequest(se::Request& request, size_t resultCount = 10)
{
    receivesRequest(request.getRequest(), resultCount);
}

void se::NMultiQueryHandler::receivesRequest(std::vector<std::string> const& requests, size_t resultCount = 10)
{
    m_requests.clear();
    m_result.clear();
    
    std::vector<std::string> new_requests = requests;
    std::cout<<"NMultiQueryHandler ::receivesRequest:: new_requests.size() = "<<new_requests.size()<<std::endl;
    if(new_requests.size() == 0){
        m_ptrResult = nullptr;
    }

    se::Result myResult(std::vector<std::pair<std::string, size_t>>{});
    for(size_t i = 0 ; i<  new_requests.size() ; ++i){
        std::cout<<"new_requests[i]"<<new_requests[i]<<std::endl;
        SimpleRequest simpleRequest(new_requests[i]);
        m_simpleQueryHandler.receivesRequest(simpleRequest, 100);///???
        auto result = m_simpleQueryHandler.returnResult();
        if(result != nullptr){
            std::cout<<new_requests[i] <<" :: NMultiQueryHandler ::receivesRequest:: result->.size() = "<<result->getResult().size()<<std::endl;
            myResult = myResult | (*result);
        }
    }

    for(auto const& pair : myResult.getResult()){
        std::cout<<pair.first <<" :: pair.first "<<std::endl;
        m_result.push_back(pair);
    }
    std::sort(m_result.begin(), m_result.end(),[](auto pair1 ,auto pair2){return pair1.second > pair2.second;});

    auto it = m_result.begin();
    for(size_t i = 0 ; i < resultCount && it != m_result.end(); ++i){
        ++it;
    }
    m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
}

std::unique_ptr<se::Result> se::NMultiQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}

bool se::NMultiQueryHandler::checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link){
    for(size_t i = 0 ; i < words.size() ; ++i){
        if(!m_searchDB.wordAndLinkExis(words[i], link)){
            return false;
        }
    }
    return true;
}