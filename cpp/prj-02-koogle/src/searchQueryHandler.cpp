#include "searchQueryHandler.hpp"

se::SearchQueryHandler::SearchQueryHandler(SearchDB const& searchDB)
: m_SearchDB(searchDB)
{}

std::vector<std::pair<std::string, size_t>> se::SearchQueryHandler::stripConst(std::vector<std::pair<const std::string, size_t>>& vecResult)
{
    std::vector<std::pair<std::string, size_t>> result;
    for(auto const& pair : vecResult){
        result.push_back(std::pair(pair.first, pair.second));
    }
    return result;
}

void se::SearchQueryHandler::receivesRequest(se::Request& request)
{
    m_ptrResult = nullptr;//??
    m_result.clear();
    try
    {
        auto new_request = dynamic_cast<se::SimpleRequest&>(request);
        std::string const& word = new_request.getRequest()[0];
        auto mapResult = m_SearchDB.searchWord(word);
        for(auto const& pair : mapResult){
            m_result.push_back(pair);
        }
        std::sort(m_result.begin(), m_result.end(),[](auto pair1 ,auto pair2){return pair1.second > pair2.second;});
        
        auto it = m_result.begin();
        for(size_t i = 0 ; i < 10 && it != m_result.end(); ++i){
            ++it;
        }
        m_ptrResult = std::make_unique<se::Result>(std::vector(m_result.begin(),it));
    }
    catch(const std::bad_cast& e)
    {
        std::cout << e.what() << '\n';
    }
}

std::unique_ptr<se::ResultIF> se::SearchQueryHandler::returnResult()
{
    return std::move(m_ptrResult);
}
