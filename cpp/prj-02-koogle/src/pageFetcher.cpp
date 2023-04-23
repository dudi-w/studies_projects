#include "pageFetcher.hpp"
#include "getHTTP.hpp"
#include "linkParser.hpp"
#include "myExceptions.hpp"

se::PageFetcher::PageFetcher(se::CrawlerIF& crawler)
: m_crawler(crawler)
{}

void se::PageFetcher::startDownlaod()
{
    while(true){
        if(std::string url = m_crawler.getURLtoDownlaod() ; url != ""){
            try{
                auto page = getHTTPpage(url);
                m_crawler.updatePage(page);
            }
            catch(const curlpp::LibcurlRuntimeError& e)
            {
                std::cout<<"\033[3;31mERROR: can't laod url \033[0m"<<url<<std::endl;
                continue;
            }
            /*catch(...)*/
        }else{
            /*if !allThreadFinshed()*/
            /*else*/
            break;
        }
    }
}
