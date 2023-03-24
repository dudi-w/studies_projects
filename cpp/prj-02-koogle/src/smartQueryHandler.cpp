#include "smartQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::SmartQueryHandler::SmartQueryHandler(SearchDB const& searchDB)
: m_SearchDB(searchDB)
{}

void se::SmartQueryHandler::receivesRequest(se::Request& request)
{
    m_result.clear();
    auto new_request = dynamic_cast<se::SimpleRequest&>(request);
    std::string word = new_request.getRequest();
    makeLowercase(word);

    std::stringstream ss(word);
    while(ss >> word){
        if(m_SearchDB.wordExis(word)){
            m_requests.push_back(word);
        }else{
            m_ptrResult = nullptr;
            return;
        }
    }

    auto& mapResult = m_SearchDB.searchWord(word);
    
    for(auto const& pair : mapResult){
        m_result.push_back(pair);
    }
    std::sort(m_result.begin(), m_result.end(),[](auto pair1 ,auto pair2){return pair1.second > pair2.second;});

    auto it = m_result.begin();
    u_char j = 0;
    while(it != m_result.end() && j < 10){
        if(!checkLinkExistsInAllWrds(m_requests ,it->first) && checkLinkMotExistsInWrds()){
            it = m_result.erase(it);
        }else{
            ++j;
            ++it;
        }
    }
    if(it == m_result.begin()){
        m_ptrResult = nullptr;
        return;
    }
    m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
}

std::unique_ptr<se::ResultIF> se::SmartQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}

bool se::SmartQueryHandler::checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link){
    for(size_t i = 0 ; i < words.size() ; ++i){
        if(not m_SearchDB.wordAndLinkExis(words[i], link)){
            return false;
        }
    }
    return true;
}

bool se::SmartQueryHandler::checkLinkMotExistsInWrds(std::vector<std::string> const& words, std::string const& link){
    for(size_t i = 0 ; i < words.size() ; ++i){
        if(m_SearchDB.wordAndLinkExis(words[i], link)){
            return false;
        }
    }
    return true;
}
