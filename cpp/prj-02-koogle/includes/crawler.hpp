#ifndef CRAWLER_HPP
#define CRAWLER_HPP

#include <unordered_set>
#include <queue>

#include "crawlerIF.hpp"
#include "getHTTP2.hpp"
#include "analyzPage.hpp"
#include "dataLoader.hpp"

namespace se{//Search Engine

class Crawler : public CrawlerIF
{
public:
    explicit Crawler(se::DataLoader& dataLoader, std::string srcURL, size_t maxPages, size_t maxDepth, bool bounded);
    explicit Crawler(se::DataLoader& dataLoader, Configuration configuration);
    Crawler(Crawler const& other) = default;
    Crawler& operator=(Crawler const& other) = default;
    virtual ~Crawler() {std::cout<<"~Crawler\n"<<std::endl;}

    void startCrawling() override;
    void insertInQueue(std::vector<std::string> const& links) override;

private:
    void insertLinkInQueue(std::string const& link);
    void insertURLAsSearched(std::string const& link);
    std::string getURLToSearch();

private:
    std::unordered_set<std::string> m_searchedLinks;
    std::queue<std::string> m_crawlingQueue;
    se::DataLoader& m_dataLoader;
    se::Configuration m_configuration;
};

}//namespace se

#endif
