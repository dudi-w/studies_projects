#include <fstream>
#include <nlohmann/json.hpp>

#include "crawler.hpp"

se::Crawler::Crawler(std::string const& configurationFilePath, se::SetDB& searchDatabase)
: m_mataDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
, m_pageFetcher(*this)
{
    auto& configuration = se::Configuration::getInstance(configurationFilePath);
    m_queue = se::CrawlerQueue(configuration);
}

void se::Crawler::startCrawling()
{
    m_pageFetcher.startDownlaod();
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
    m_queue.markURLAsSearched(page.getSrc());
    m_queue.inQueue(links);
}

std::string se::Crawler::getURLtoDownlaod()
{
    return m_queue.deQueue();
}