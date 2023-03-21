#include "searchDatabase.hpp"

std::unordered_map<std::string ,size_t> const& se::SearchDB::searchWord(std::string const& word) const
{
    return m_wordsIndex.at(word);//exception
}

size_t se::SearchDB::linkOccurrenceCount(std::string const& link1, std::string const& link2) const
{
    try
    {
        return m_linksMap.at(link1).at(link2);
    }
    catch(std::out_of_range& e)
    {
        return 0;
    }
}

void se::SearchDB::insertLinks(std::string const& srcLink, std::vector<std::string> const& links)
{
    if(!m_linksMap.count(srcLink)){
        m_linksMap[srcLink];//???
        for(auto const & link : links){
            insertLink(srcLink ,link);
        }
    }else{
        throw 1;//exception
    }
}

void se::SearchDB::insertLink(std::string const& srcLink, std::string const& link)
{
    if(!m_linksMap[srcLink].count(link)){
        m_linksMap[srcLink][link] = 1;
    }else{
        m_linksMap[srcLink][link] += 1;
    }
}

void se::SearchDB::insertWords(std::string const& srcLink, std::vector<std::string> const& words)
{
    for(auto const & word : words){
        if(!m_wordsIndex.count(word) || !m_wordsIndex.at(word).count(srcLink)){
            m_wordsIndex[word][srcLink] = 1;
        }else{
            m_wordsIndex[word][srcLink] += 1;
        }
    }
}