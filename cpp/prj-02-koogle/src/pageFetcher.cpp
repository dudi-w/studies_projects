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
    std::cout<< "m_activesTreads"<<m_activesTreads<< " \033[3;34mthread id :"<<std::this_thread::get_id()<<"go sleep\033[0m"<<std::endl;
    while(!m_newUrlInQueue){
        std::cout<< "m_activesTread = "<<m_activesTreads<<std::endl;
        std::cout<<std::boolalpha<<"\033[3;34m"<< m_newUrlInQueue<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(m_activesTreads <= 0){
            return false;
        }
    }
    ++m_activesTreads;
    std::cout<< m_activesTreads<<" \033[3;31mthread id :"<<std::this_thread::get_id()<<"is weak up\033[0m"<<std::endl;
    return true;
}

void se::PageFetcher::startDownlaod()
{
    while(true){
        if(std::string url = m_crawler.getURLtoDownlaod() ; !url.empty()){
            try{
                std::cout<< "\033[3;36murl = "<<url<<std::endl;
                std::cout<< "\033[3;32mthread id :"<<std::this_thread::get_id()<<" is active\033[0m"<<std::endl;
                std::cout<< m_activesTreads<<std::endl;
                std::cout<<std::boolalpha<< m_newUrlInQueue<<std::endl;
                auto page = getHTTPpage(url);
                m_crawler.updatePage(page);
            }
            catch(const curlpp::LibcurlRuntimeError& e){
                std::clog<<"\033[3;31mERROR: can't laod url \033[0m"<<url<<std::endl;
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
