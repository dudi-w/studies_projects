// #include <fstream>
#include <nlohmann/json.hpp>

#include "crawler.hpp"
#include "systemMonitor.hpp"
#include "configuration.hpp"

se::Crawler::Crawler(se::SetDB& searchDatabase)
: m_mataDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
, m_pageFetcher(*this)
{
    se::SystemMonitor::start();
    for(size_t i = 0 ; i < se::Configuration::maxThreads() ; ++i){
        m_threads.emplace_back([this](){ m_pageFetcher.startDownlaod();});
    }
}

se::Crawler::~Crawler()
{
    for(auto & tread : m_threads){
        tread.join();
    }
}

void se::Crawler::updatePage(AnalyzPage const& page)
{
    auto parsPage = m_parser.pars(std::make_unique<se::BasePage>(page));
    auto srcPage = parsPage.getSrc();
    auto links = parsPage.getLinks();
    auto words = parsPage.getWords();
    std::cout<<words.size()<<" updatePage\n";
    m_mataDatabase.insertLinks(srcPage, links);
    m_mataDatabase.insertWords(srcPage, words);
    m_queue.inQueue(links);
}

std::string se::Crawler::getURLtoDownlaod()
{
    return m_queue.deQueue();
}
