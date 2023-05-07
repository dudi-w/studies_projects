// #include <chrono>
#include <fstream>
#include <nlohmann/json.hpp>

#include "crawler.hpp"

se::Crawler::Crawler(se::SetDB& searchDatabase)
: m_mataDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
, m_pageFetcher(*this)
{
    for(size_t i = 0 ; i < se::Configuration::maxThreads() ; ++i){
        m_threads.emplace_back([this](){ m_pageFetcher.startDownlaod();});
    }
    // auto start_time = std::chrono::high_resolution_clock::now();
    // auto end_time = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    // std::cout << "Execution time: " << duration.count() << " microseconds\n";
    // m_mataDatabase.log();
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
    m_mataDatabase.insertLinks(srcPage, links);
    m_mataDatabase.insertWords(srcPage, words);
    m_queue.inQueue(links);
}

std::string se::Crawler::getURLtoDownlaod()
{
    return m_queue.deQueue();
}
