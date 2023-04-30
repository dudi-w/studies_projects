#include <thread>
#include <chrono>

#include "pageFetcher.hpp"
#include "getHTTP.hpp"
#include "linkParser.hpp"
#include "myExceptions.hpp"
#include "configuration.hpp"

se::PageFetcher::PageFetcher(se::CrawlerIF& crawler)
: m_crawler(crawler)
, m_newUrlInQueue(false)
, m_activesTreads(static_cast<int>(se::Configuration::maxThreads()))
{}


void se::PageFetcher::startDownlaod()
{
    while(true){
        if(std::string url = m_crawler.getURLtoDownlaod() ; !url.empty()){
            try{
                auto page = getHTTPpage(url);
                m_crawler.updatePage(page);
            }
            catch(const curlpp::LibcurlRuntimeError& e){
                std::cerr<<"\033[3;31mERROR: can't laod url \033[0m"<<url<<std::endl;
                continue;
            }
        }
        else{
            break;;
        }
    }
}
