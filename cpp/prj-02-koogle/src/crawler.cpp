#include "crawler.hpp"
#include "myExceptions.hpp"

se::Crawler::Crawler(DataLoader& dataLoader, std::string srcURL, size_t maxPages, size_t maxDepth, bool bounded)
: m_dataLoader(dataLoader)
{
    m_configuration.srcURL = srcURL;
    m_configuration.maxPages = maxPages;
    m_configuration.maxDepth = maxDepth;
    m_configuration.bounded = bounded;
}

se::Crawler::Crawler(DataLoader& dataLoader, Configuration configuration)
: m_dataLoader(dataLoader)
{
    m_configuration.srcURL = configuration.srcURL;
    m_configuration.maxPages = configuration.maxPages;
    m_configuration.maxDepth = configuration.maxDepth;
    m_configuration.bounded = configuration.bounded;
    m_crawlingQueue.push(m_configuration.srcURL);
    std::cout<<"\033[3;32mTEST Crawler"<<m_configuration.srcURL<<"\033[0m\n";
}

void se::Crawler::startCrawling()
{
    std::string url;
    while(!m_crawlingQueue.empty() && m_searchedLinks.size() < m_configuration.maxPages){
        url = getURLToSearch();
        if(url != ""){
            try{
                std::cout<<"dvsdwb"<<std::endl;
                auto page = getHTTPpage(url);
                // auto newURLs = m_dataLoader.updatePage(page);
                m_dataLoader.updatePage(page);
                insertURLAsSearched(url);
                // insertInQueue(newURLs);
                url.clear();
            }
            catch(const curlpp::LibcurlRuntimeError& e)
            {
                continue;
            }
        }
    }     
    std::cout<<"\033[3;32mcatch(const curlpp::LibcurlRuntimeError& e)\033[0m\n";
}

void se::Crawler::insertURLAsSearched(std::string const& link)
{
    if(!m_searchedLinks.count(link)){
        std::cout<<"done uml = \033[1;33m"<<link<<"\033[0m ;\n"<<std::endl;
        m_searchedLinks.insert(link);
    }else{
        throw 1;
    }
}

std::string se::Crawler::getURLToSearch()
{
    if(!m_crawlingQueue.empty()){
        std::string link = m_crawlingQueue.front();
        std::cout<<"\033[3;32m!m_crawlingQueue.empty "<<m_crawlingQueue.size()<<link<<"\033[0m\n";
        m_crawlingQueue.pop();
        if(!m_searchedLinks.count(link)){
            std::cout<<"\033[3;32m!m_crawlingQueue.empty "<<link<<"\033[0m\n";
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
    std::cout<<"\033[3;31minsertInQueue\033[0m"<<std::endl;
    if(!m_searchedLinks.count(link)){
        m_crawlingQueue.push(link);
    }

}

void se::Crawler::insertInQueue(std::vector<std::string> const& links)
{
    std::cout<<"\033[3;31mm_crawlingQueue.size = "<<m_crawlingQueue.size()<<"\033[0m"<<std::endl;
    for(auto const& link : links){
        std::cout<<"\033[3;31mlink = "<<link<<"\033[0m"<<std::endl;
        this->insertLinkInQueue(link);
    }
}
