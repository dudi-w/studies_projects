#include <iostream>
// #include <fstream>
#include <nlohmann/json.hpp>
#include <thread>
#include <vector>

#include "myExceptions.hpp"
#include "crawler.hpp"

se::Crawler::Crawler(se::SetDB& searchDatabase)
: m_mataDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
, m_queue(se::Configuration::getSrcURLs(), se::Configuration::maxPages(), se::Configuration::isBounded())
, m_pageFetcher(*this)
{}

void se::Crawler::startCrawling()
{
    // std::cout<<se::Configuration::maxThreads()<<std::endl;
    auto maxThreads = se::Configuration::maxThreads();
    std::vector<std::thread> threads(maxThreads);
    for(size_t i = 0; i < maxThreads; ++i){
        threads[i] = std::thread([&](){ m_pageFetcher.startDownlaod(); });
    }
    for(size_t i = 0; i < maxThreads; ++i){
        threads[i].join();
    }
    m_mataDatabase.log();
}

void se::Crawler::updatePage(AnalyzPage const& page)
{
    auto parsPage = m_parser.pars(std::make_unique<se::BasePage>(page));
    auto srcPage = parsPage.getSrc();
    auto links = parsPage.getLinks();
    auto words = parsPage.getWords();
    m_mataDatabase.insertLinks(srcPage, links);
    m_mataDatabase.insertWords(srcPage, words);
    // m_queue.markURLAsSearched(page.getSrc());
    m_queue.inQueue(links);
    m_pageFetcher.notificationForNewUrls();
}

// std::string se::Crawler::getURLtoDownlaod()
// {
//     return m_queue.deQueue();
// }

std::string se::Crawler::getURLtoDownlaod()
{
    auto url = m_queue.deQueue();
    if(!url.empty()){
        try{
            m_queue.markURLAsSearched(url);
        }
        catch(const se::SearchError& e)
        {
            std::cerr << e.what() << '\n';
            return getURLtoDownlaod();
        }
        
    }
    return url;
}
