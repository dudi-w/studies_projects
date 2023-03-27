#include <limits>

#include "smartQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::SmartQueryHandler::SmartQueryHandler(se::GetDB const& searchDB)
: m_NMultiQueryHandler(searchDB)
, m_PMultiQueryHandler(searchDB)
{}

void se::SmartQueryHandler::receivesRequest(se::Request& request, size_t resultCount)
{
    
    m_result.clear();
    m_negativeRequests.clear();
    m_requests.clear();

    std::vector<std::string> new_requests = request.getRequest();
    if(new_requests.size() == 0){
        m_ptrResult = nullptr;
        return;
    }

    for(auto& request : new_requests){
        std::cout<<"\033[1;35m"<<request<<std::endl;
        auto startsWith = [](std::string const &s, std::string const &w){return !s.compare(0, w.size(), w);};
        if(startsWith(request,"-")){
            m_negativeRequests.push_back(request.substr(1));
        }else{
            m_requests.push_back(request);
        }
    }
    if(m_requests.size() == 0 && m_negativeRequests.size() > 0){
        m_ptrResult = nullptr;
        return;
    }
    /***********************************************/
    for(auto& i : m_requests){
        std::cout<<"\033[1;33mm_requests = "<<i<<"\033[0m"<<std::endl;
    }
    for(auto& i : m_negativeRequests){
        std::cout<<"\033[1;32m m_negativeRequests = "<<i<<"\033[0m"<<std::endl;
    }
    /**********************************************/
    m_PMultiQueryHandler.receivesRequest(m_requests ,std::numeric_limits<int>::max());
    auto P_Result = m_PMultiQueryHandler.returnResult();
    if(P_Result == nullptr){
        m_ptrResult = nullptr;
        return;
    }
    se::Result myResult(*P_Result);
    /**************************************************/
    for(auto& i : m_requests){
        std::cout<<"\033[1;33m"<<i<<"\033[0m"<<std::endl;
    }
    for(auto& i : m_negativeRequests){
        std::cout<<"\033[1;32m"<<i<<"\033[0m"<<std::endl;
    }
    /**************************************************/
    m_NMultiQueryHandler.receivesRequest(m_negativeRequests, std::numeric_limits<int>::max());
    auto N_Result = m_NMultiQueryHandler.returnResult();
    if(N_Result != nullptr){
        std::cout<<"\033[1;32mN_Result->getResult().size() = "<<N_Result->getResult().size()<<"\033[0m"<<std::endl;
        myResult = myResult - (*N_Result);
    }
    if(myResult.getResult().size()==0){
        m_ptrResult = nullptr;
        return;
    }
    for(auto const& pair : myResult.getResult()){
        m_result.push_back(pair);
    }
    std::sort(m_result.begin(), m_result.end(),[](auto pair1 ,auto pair2){return pair1.second > pair2.second;});

    auto it = m_result.begin();
    for(size_t i = 0 ; i < resultCount && it != m_result.end(); ++i){
        ++it;
    }
    m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
}

std::unique_ptr<se::Result> se::SmartQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}