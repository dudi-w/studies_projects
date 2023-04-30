#include <fstream>
#include <nlohmann/json.hpp>
#include <thread>
#include <vector>
#include <iostream>

#include "crawler.hpp"

se::Crawler::Crawler(se::SetDB& searchDatabase)
: m_mataDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
, m_pageFetcher(*this)
{}

void se::Crawler::startCrawling()
{
    std::vector<std::thread> threads(se::Configuration::maxThreads()); 
    for(size_t i = 0; i < se::Configuration::maxThreads(); ++i){
        threads[i] = std::thread([&](){ m_pageFetcher.startDownlaod(); });
    }
    for(size_t i = 0; i < se::Configuration::maxThreads(); ++i){
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
    m_queue.inQueue(links);
}

std::string se::Crawler::getURLtoDownlaod()
{
    return m_queue.deQueue();
}
