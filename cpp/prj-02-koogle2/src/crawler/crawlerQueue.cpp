#include <iostream>
#include "crawlerQueue.hpp"
#include "myExceptions.hpp"
#include "getHTTP.hpp"
#include "linkParser.hpp"
#include "tools.hpp"

se::CrawlerQueue::CrawlerQueue(se::Configuration const& configuration)
{
    m_configuration.srcURL = configuration.getSrcURLs();
    m_configuration.maxPages = configuration.maxPages();
    m_configuration.bounded = configuration.isBounded();
    srcURLValidation();
    if(m_configuration.bounded){
        extractSrcPrefix();
    }
    inQueue(m_configuration.srcURL);
}

void se::CrawlerQueue::markURLAsSearched(std::string const& link)
{
    if(!m_searchedLinks.count(link)){
        std::clog<<"\U0001F525 \033[1;33m"<<link<<"\033[0m. \U0001F525\n"<<std::endl;
        m_searchedLinks.insert(link);
    }else{
        throw se::SearchError("duplecat Searched " + link);
    }
}

std::string se::CrawlerQueue::deQueue()
{
    while(true){
        if(!m_queue.empty() && !(m_searchedLinks.size() >= m_configuration.maxPages)){
            std::string link = m_queue.front();
            m_queue.pop();
            if(!m_searchedLinks.count(link)){
                return link;
            }
        }else{
            return "";
        }
    }
    
}

void se::CrawlerQueue::inQueue(std::string const& link)
{
    if(!m_searchedLinks.count(link) && ifBounded(link)){
        m_queue.push(link);
    }
}

void se::CrawlerQueue::inQueue(std::vector<std::string> const& links)
{
    for(auto const& link : links){
        inQueue(link);
    }
}

void se::CrawlerQueue::srcURLValidation()
{
    for(auto const& url : m_configuration.srcURL){
        try{
            isNetworkConnected();
            getHTTPpage(url);
        }
        catch(const curlpp::LibcurlRuntimeError & e)
        {
            throw se::InValidSrcURL("can't laod src url " + url);
        }
    }
}

void se::CrawlerQueue::extractSrcPrefix()
{
    std::string prefix;
    for(size_t i =0 ; i < m_configuration.srcURL.size(); ++i){
        m_homeAddress.reserve(m_configuration.srcURL.size());
        extractPrefix(m_configuration.srcURL[i], prefix);
        m_homeAddress.push_back(prefix);
    }
}

bool se::CrawlerQueue::ifBounded(std::string const& link) const
{
    if(!m_configuration.bounded){
        return true;
    }else{
        std::string currentHomeAddress;
        extractPrefix(link, currentHomeAddress);
        auto lambda = [currentHomeAddress](auto const& HomeAddress){return HomeAddress == currentHomeAddress;};
        return std::any_of(m_homeAddress.cbegin(), m_homeAddress.cend(), lambda);
    }
}

