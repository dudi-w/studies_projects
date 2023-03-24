#include "simpleQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"

se::SimpleQueryHandler::SimpleQueryHandler(SearchDB const& searchDB)
: m_SearchDB(searchDB)
{}

void se::SimpleQueryHandler::receivesRequest(se::Request& request)
{
    
    m_result.clear();
    auto new_request = dynamic_cast<se::SimpleRequest&>(request);
    std::string word = new_request.getRequest();
    makeLowercase(word);

    if(m_SearchDB.wordExis(word)){
        auto& mapResult = m_SearchDB.searchWord(word);
        for(auto const& pair : mapResult){
            m_result.push_back(pair);
        }
        std::sort(m_result.begin(), m_result.end(),[](auto pair1 ,auto pair2){return pair1.second > pair2.second;});

        auto it = m_result.begin();
        for(size_t i = 0 ; i < 10 && it != m_result.end(); ++i){
            // std::cout<<it->first<<"  "<<it->second<<std::endl;
            ++it;
        }
        m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
    }else{
        m_ptrResult = nullptr;
    }
}

std::unique_ptr<se::ResultIF> se::SimpleQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}
