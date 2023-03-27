#include "crawler.hpp"
#include "getHTTP.hpp"
#include "myExceptions.hpp"

se::Crawler::Crawler(DataLoader& dataLoader, std::vector<std::string> srcURL, size_t maxPages, size_t maxDepth, bool bounded)
: m_dataLoader(dataLoader)
{
    m_configuration.srcURL = srcURL;
    m_configuration.maxPages = maxPages;
    m_configuration.maxDepth = maxDepth;
    m_configuration.bounded = bounded;
    srcURLValidation();
    for(auto& url : m_configuration.srcURL){
        m_crawlingQueue.push(url);
    }
}

se::Crawler::Crawler(DataLoader& dataLoader, Configuration configuration)
: Crawler(dataLoader, configuration.srcURL, configuration.maxPages, configuration.maxDepth, configuration.bounded)
{}

void se::Crawler::startCrawling()
{
    std::string url;
    while(!m_crawlingQueue.empty() && m_searchedLinks.size() < m_configuration.maxPages){
        if(url = getURLToSearch() ; url != ""){
            try{
                // isNetworkConnected();
                auto page = getHTTPpage(url);
                m_dataLoader.updatePage(page);
                insertURLAsSearched(url);
                url.clear();
            }
            catch(const curlpp::LibcurlRuntimeError& e)
            {
                std::cout<<"\033[3;31mERROR: can't laod url \033[0m"<<url<<std::endl;
                continue;
            }
        }
    }     
}

void se::Crawler::insertURLAsSearched(std::string const& link)
{
    if(!m_searchedLinks.count(link)){
        std::cout<<"\U0001F525 \033[1;33m"<<link<<"\033[0m; \U0001F525\n"<<std::endl;
        m_searchedLinks.insert(link);
    }else{
        throw std::runtime_error("duplecat Searched " + link);
    }
}

std::string se::Crawler::getURLToSearch()
{
    if(!m_crawlingQueue.empty()){
        std::string link = m_crawlingQueue.front();
        m_crawlingQueue.pop();
        if(!m_searchedLinks.count(link)){
            return link;
        }else{
            return getURLToSearch();
        }
    }else{
        return "";
    }
}

void se::Crawler::insertLinkInQueue(std::string const& link)
{
    if(!m_searchedLinks.count(link)){
        m_crawlingQueue.push(link);
    }

}

void se::Crawler::insertInQueue(std::vector<std::string> const& links)
{
    for(auto const& link : links){
        this->insertLinkInQueue(link);
    }
}

void se::Crawler::srcURLValidation()
{
    try{
        isNetworkConnected();
        getHTTPpage(m_configuration.srcURL.front());
    }
    catch(const curlpp::LibcurlRuntimeError & e)
    {
        throw se::InValidSrcURL("can't laod src url " + m_configuration.srcURL.front());
    }
}

void isNetworkConnected()
{
    if(system("ping -c 1 google.com >> /dev/null")) {
        throw se::CommunicationError("Check your network connection");
    }
}
