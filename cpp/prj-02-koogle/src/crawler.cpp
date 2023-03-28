#include "crawler.hpp"
#include "getHTTP.hpp"
#include "linkParser.hpp"
#include "myExceptions.hpp"

se::Crawler::Crawler(DataLoader& dataLoader, std::vector<std::string> srcURL, size_t maxPages, bool bounded)
: m_dataLoader(dataLoader)
{
    m_configuration.srcURL = srcURL;
    m_configuration.maxPages = maxPages;
    m_configuration.bounded = bounded;
    srcURLValidation();
    for(size_t i =0 ; i < m_configuration.srcURL.size(); ++i){
        m_crawlingQueue.push(m_configuration.srcURL[i]);
        if(m_configuration.bounded){
            m_homeAddress.reserve(m_configuration.srcURL.size());
            std::string prefix;
            extractPrefix(m_configuration.srcURL[i], prefix);
            m_homeAddress.push_back(prefix);
        }
    }
}

se::Crawler::Crawler(DataLoader& dataLoader, Configuration configuration)
: Crawler(dataLoader, configuration.srcURL, configuration.maxPages, configuration.bounded)
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
        throw se::SeatchError("duplecat Searched " + link);
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
    if(!m_searchedLinks.count(link) && ifBounded(link)){
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

bool se::Crawler::ifBounded(std::string const& link) const
{
    if(!m_configuration.bounded){
        return true;
    }else{
        std::string currentHomeAddress;
        extractPrefix(link, currentHomeAddress);
        auto lambda = [currentHomeAddress](auto const& HomeAddress){return HomeAddress == currentHomeAddress;};
        return std::any_of(m_homeAddress.begin(), m_homeAddress.end(), lambda);
    }

}

void isNetworkConnected()
{
    if(system("ping -c 1 google.com >> /dev/null")) {
        throw se::CommunicationError("Check your network connection");
    }
}
