#ifndef CRAWLER2_HPP
#define CRAWLER2_HPP

#include <unordered_set>
#include <queue>

#include "crawlerIF.hpp"
#include "analyzPage.hpp"
#include "dataLoader.hpp"

namespace se{//Search Engine

class Crawler : public CrawlerIF
{
public:
    explicit Crawler(se::DataLoader& dataLoader, std::vector<std::string> srcURL, size_t maxPages, bool bounded);
    explicit Crawler(se::DataLoader& dataLoader, se::Configuration const& configuration);
    Crawler(Crawler const& other) = default;
    Crawler& operator=(Crawler const& other) = default;
    virtual ~Crawler() = default;

    void startCrawling() override;

private:

private:
    se::DataLoader& m_dataLoader;
    
    struct Configuration{
    std::vector<std::string> srcURL;
    size_t maxPages;
    bool bounded;
    } m_configuration;
    std::unordered_set<std::string> m_searchedLinks;
    std::queue<std::string> m_crawlingQueue;
    std::vector<std::string> m_homeAddress;
};

}//namespace se

void isNetworkConnected();

#endif
