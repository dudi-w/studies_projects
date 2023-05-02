#include <iostream>

#include "matabase.hpp"
#include "myExceptions.hpp"


void se::Matabase::log() const
{
    std::clog<<"\033[3;32mEnd of storage\033[0m\n"<<std::endl;
    std::clog<<"\tNumber of words: "<<m_wordsIndex.size()<<std::endl;
    std::clog<<"\tThe number of links: "<<m_linksMap.size()<<std::endl;
}

std::unordered_map<std::string ,size_t> const se::Matabase::getLinkOfWord(std::string const& word) const
{
    std::shared_lock lock(m_mutex);
    return m_wordsIndex.at(word);
}

void se::Matabase::insertLinks(std::string const& srcLink, std::vector<std::string> const& links)
{
    /*links-lock*/
    // std::unique_lock lock(m_mutex);
    if(!m_linksMap.count(srcLink)){
        m_linksMap[srcLink];
        for(auto const& link : links){
            insertLink(srcLink ,link);
        }
    }else{
        throw se::StorageError("Double storage of URL = " + srcLink);
    }
}

void se::Matabase::insertLink(std::string const& srcLink, std::string const& link)
{
    /*links-lock*/
    if(!m_linksMap[srcLink].count(link)){
        m_linksMap[srcLink][link] = 1;
    }else{
        m_linksMap[srcLink][link] += 1;
    }
}

void se::Matabase::insertWords(std::string const& srcLink, std::vector<std::string> const& words)
{
    std::unique_lock lock(m_mutex);
    for(auto const & word : words){
        if(!m_wordsIndex.count(word) || !m_wordsIndex.at(word).count(srcLink)){
            m_wordsIndex[word][srcLink] = 1;
        }else{
            m_wordsIndex[word][srcLink] += 1;
        }
    }
}

size_t se::Matabase::getLinkOccurrenceCount(std::string const& link1, std::string const& link2) const
{
    /*links lock*/
    std::shared_lock lock(m_mutex);
    try{
        return m_linksMap.at(link1).at(link2);
    }
    catch(std::out_of_range& e){
        return 0;
    }
}

bool se::Matabase::wordExis(std::string const& word) const
{
    std::shared_lock lock(m_mutex);
    return m_wordsIndex.count(word);
}

bool se::Matabase::wordAndLinkExis(std::string const& word, std::string const& link) const
{
    std::shared_lock lock(m_mutex);
    return !wordExis(word) ? false : m_wordsIndex.at(word).count(link);
}
