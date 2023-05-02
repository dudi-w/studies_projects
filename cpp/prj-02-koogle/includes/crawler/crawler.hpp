#ifndef CRAWLER_HPP
#define CRAWLER_HPP

#include <string>

#include "analyzPage.hpp"
#include "linkWordParser.hpp"
#include "crawlerIF.hpp"
#include "setDatabase.hpp"
#include "configuration.hpp"
#include "pageFetcher.hpp"
#include "crawlerQueue.hpp"


namespace se{//Search Engine

class Crawler : public CrawlerIF
{
public:
    explicit Crawler(se::SetDB& searchDatabase);
    Crawler(Crawler const& other) = default;
    Crawler& operator=(Crawler const& other) = default;
    ~Crawler() = default;

    void startCrawling();
    virtual void updatePage(AnalyzPage const& page) override;
    virtual std::string getURLtoDownlaod() override;
    
private:
    se::SetDB& m_mataDatabase;
    se::WordParser m_wordParser;
    se::LinkParser m_linkParser;
    se::LinkWordParser m_parser;
    se::CrawlerQueue m_queue;
    se::PageFetcher m_pageFetcher;
};

}//namespace se

#endif
