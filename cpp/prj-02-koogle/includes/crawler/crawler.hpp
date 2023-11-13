#ifndef CRAWLER_HPP
#define CRAWLER_HPP

#include <string>
#include <thread>
#include <vector>


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
    explicit Crawler(se::SetDB& matabase);
    Crawler(Crawler const& other) = delete;
    Crawler& operator=(Crawler const& other) = delete;
    ~Crawler();

    virtual void updatePage(AnalyzPage const& page) override;
    virtual std::string getURLtoDownlaod() override;
    
private:
    se::SetDB& m_mataDatabase;
    se::WordParser m_wordParser;
    se::LinkParser m_linkParser;
    se::LinkWordParser m_parser;
    se::CrawlerQueue m_queue;
    se::PageFetcher m_pageFetcher;
    std::vector<std::thread> m_threads;
};

}//namespace se

#endif
