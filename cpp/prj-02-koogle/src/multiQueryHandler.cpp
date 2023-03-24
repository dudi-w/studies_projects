#include "multiQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::MultiQueryHandler::MultiQueryHandler(SearchDB const& searchDB)
: m_SearchDB(searchDB)
{}

void se::MultiQueryHandler::receivesRequest(se::Request& request)
{
    m_result.clear();
    auto new_request = dynamic_cast<se::SimpleRequest&>(request);
    std::string word = new_request.getRequest();
    makeLowercase(word);

    std::string tmp;
    std::stringstream ss(word);
    while(ss >> tmp){
        if(m_SearchDB.wordExis(tmp)){
            m_requests.push_back(tmp);
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
        if(!checkLinkExistsInAllWrds(m_requests, it->first)){
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

std::unique_ptr<se::ResultIF> se::MultiQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}

bool se::MultiQueryHandler::checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link){
    for(size_t i = 0 ; i < words.size() ; ++i){
        if(!m_SearchDB.wordAndLinkExis(words[i], link)){
            return false;
        }
    }
    return true;
}