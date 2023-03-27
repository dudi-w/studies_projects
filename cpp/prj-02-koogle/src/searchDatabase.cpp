#include "searchDatabase.hpp"

void se::SearchDB::log() const
{
    std::cout<<"End of storage"<<std::endl;
    std::cout<<"\tNumber of words: "<<m_wordsIndex.size()<<std::endl;
    std::cout<<"\tThe number of links: "<<m_linksMap.size()<<std::endl;
    // int f = 0;
    // for(auto i : m_wordsIndex){
        // std::cout<<f<<" - "<<i.first<<std::endl;
        // ++f;
    // }
}

std::unordered_map<std::string ,size_t> const& se::SearchDB::getLinkOfWord(std::string const& word) const
{
    return m_wordsIndex.at(word);//exception
}

size_t se::SearchDB::getLinkOccurrenceCount(std::string const& link1, std::string const& link2) const
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
        for(auto const& link : links){
            // std::cout<<link<<std::endl;
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
        // std::cout<<word<<std::endl;
        if(!m_wordsIndex.count(word) || !m_wordsIndex.at(word).count(srcLink)){
            m_wordsIndex[word][srcLink] = 1;
        }else{
            m_wordsIndex[word][srcLink] += 1;
        }
    }
}

bool se::SearchDB::wordExis(std::string const& word) const
{
    return m_wordsIndex.count(word);
}

bool se::SearchDB::wordAndLinkExis(std::string const& word, std::string const& link) const
{
    return !wordExis(word) ? false : m_wordsIndex.at(word).count(link);
}
