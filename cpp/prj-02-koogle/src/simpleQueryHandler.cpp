#include "simpleQueryHandler.hpp"
#include "simpleRequest.hpp"
#include "result.hpp"
#include "wordParser.hpp"
#include "myExceptions.hpp"

se::SimpleQueryHandler::SimpleQueryHandler(se::GetDB const& searchDB)
: m_SearchDB(searchDB)
, m_result({})
{}

void se::SimpleQueryHandler::receivesRequest(se::Request& request, size_t resultCount)
{
    if(request.getRequest().size() != 1){
        throw se::InValidArg("Only one argument is required");
    }
    receivesRequest(request.getRequest()[0], resultCount);
}

void se::SimpleQueryHandler::receivesRequest(std::string const& request, size_t resultCount)
{
    m_result = se::Result({});
    m_VecResult.clear();

    std::string word = request;

    if(m_SearchDB.wordExis(word)){
        auto& mapResult = m_SearchDB.getLinkOfWord(word);
        for(auto const& pair : mapResult){
            m_VecResult.push_back(pair);
        }
        std::sort(m_VecResult.begin(), m_VecResult.end(), [](auto pair1 ,auto pair2){return pair1.second > pair2.second;});

        auto it = m_VecResult.begin();
        for(size_t i = 0 ; i < resultCount && it != m_VecResult.end(); ++i){
            ++it;
        }
        m_result = se::Result(std::vector(m_VecResult.begin(),it));
    }
}

se::Result se::SimpleQueryHandler::returnResult()
{
    return m_result;
}
