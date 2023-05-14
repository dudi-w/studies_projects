#include "simpleQueryHandler.hpp"
#include "request.hpp"
#include "result.hpp"
#include "wordParser.hpp"
#include "myExceptions.hpp"

se::SimpleQueryHandler::SimpleQueryHandler(se::GetDB const& searchDB)
: m_SearchDB(searchDB)
, m_result({})
{}

void se::SimpleQueryHandler::receivesRequest(se::RequestIF& request)
{
    if(request.getRequest().size() != 1){
        throw se::InValidArg("Only one argument is required");
    }
    receivesRequest(request.getRequest()[0]);
}
using LinkVec = std::vector<std::pair<std::string, size_t>>;

void se::SimpleQueryHandler::receivesRequest(std::string const& request)
{
    m_result = se::Result({});
    m_VecResult.clear();

    std::string word = request;

    if(m_SearchDB.wordExis(word)){
        auto mapResult = m_SearchDB.getLinkOfWord(word);
        m_VecResult = LinkVec(mapResult.cbegin(), mapResult.cend());
        std::sort(m_VecResult.begin(), m_VecResult.end(), [](auto pair1 ,auto pair2){return pair1.second > pair2.second;});
        m_result = std::move(se::Result(m_VecResult));
    }
}

se::Result se::SimpleQueryHandler::returnResult()
{
    return m_result;
}
