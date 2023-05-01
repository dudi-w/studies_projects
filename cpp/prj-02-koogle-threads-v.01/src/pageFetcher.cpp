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

void se::PageFetcher::notificationForNewUrls()
{
    m_newUrlInQueue = true;
}

bool se::PageFetcher::sleepRoom()
{
    m_newUrlInQueue = false;
    --m_activesTreads;
    while(!m_newUrlInQueue){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(m_activesTreads <= 0){
            return false;
        }
    }
    ++m_activesTreads;
    return true;
}

void se::PageFetcher::startDownlaod()
{
    while(true){
        if(std::string url = m_crawler.getURLtoDownlaod() ; !url.empty()){
            try{
                std::cout<< "\033[3;32mthread id :"<<std::this_thread::get_id()<<" is active\033[0m"<<std::endl;
                auto page = getHTTPpage(url);
                m_crawler.updatePage(page);
            }
            catch(const curlpp::LibcurlRuntimeError& e){
                continue;
            }
        }
        else{
            if(sleepRoom()){
                continue;
            }else{
                return;
            }
        }
    }
}
