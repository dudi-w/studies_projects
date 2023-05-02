#include <iostream>
#include <thread>

#include "crawlerQueue.hpp"
#include "myExceptions.hpp"
#include "getHTTP.hpp"
#include "linkParser.hpp"
#include "tools.hpp"

// , m_condition([&](){return !(m_searchedLinks.size() < se::Configuration::maxPages() && (m_waiting < se::Configuration::maxThreads()) && m_queue.empty());})
se::CrawlerQueue::CrawlerQueue()
: m_waiting(0)
{
    srcURLValidation();
    if(se::Configuration::isBounded()){
        extractSrcPrefix();
    }
    inQueue(se::Configuration::getSrcURLs());
}

void se::CrawlerQueue::markURLAsActive(std::string const& link)
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
    std::unique_lock lock(m_mutexMode);
    while(true){
        if(!m_queue.empty() && !(m_searchedLinks.size() >= se::Configuration::maxPages())){
            std::string link = m_queue.front();
            m_queue.pop();
            if(link.empty() || !m_searchedLinks.count(link)){
                markURLAsActive(link);
                return link;
            }else{
                continue;
            }
        }else{
            ++m_waiting;
            if(m_searchedLinks.size() >= se::Configuration::maxPages() || m_waiting >= se::Configuration::maxThreads()){
                m_cv.notify_all();
                return "";
            }
            m_cv.wait(lock ,[this](){return waitCondition();});
        }
    }
}

void se::CrawlerQueue::inQueue(std::string const& link)
{
    std::unique_lock lock(m_mutexMode);
    if(!m_searchedLinks.count(link) && ifBounded(link)){
        m_cv.notify_one();
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
    for(auto const& url : se::Configuration::getSrcURLs()){
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
    for(size_t i = 0 ; i < se::Configuration::getSrcURLs().size(); ++i){
        m_homeAddress.reserve(se::Configuration::getSrcURLs().size());
        extractPrefix(se::Configuration::getSrcURLs()[i], prefix);
        m_homeAddress.push_back(prefix);
    }
}

bool se::CrawlerQueue::ifBounded(std::string const& link) const
{
    if(!se::Configuration::isBounded()){
        return true;
    }else{
        std::string currentHomeAddress;
        extractPrefix(link, currentHomeAddress);
        auto lambda = [currentHomeAddress](auto const& HomeAddress){return HomeAddress == currentHomeAddress;};
        return std::any_of(m_homeAddress.cbegin(), m_homeAddress.cend(), lambda);
    }
}

bool se::CrawlerQueue::waitCondition()
{
    return !(m_searchedLinks.size() < se::Configuration::maxPages() &&\
        (m_waiting < se::Configuration::maxThreads()) &&\
        m_queue.empty());
}