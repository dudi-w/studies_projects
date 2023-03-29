#ifndef CRAWLER_HPP
#define CRAWLER_HPP

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
    void insertInQueue(std::vector<std::string> const& links) override;

private:
    void srcURLValidation();
    void insertLinkInQueue(std::string const& link);
    void insertURLAsSearched(std::string const& link);
    std::string getURLToSearch();
    bool ifBounded(std::string const& link) const;

private:
    struct Configuration
    {
    std::vector<std::string> srcURL;
    size_t maxPages;
    bool bounded;
    } m_configuration;
    std::unordered_set<std::string> m_searchedLinks;
    std::queue<std::string> m_crawlingQueue;
    se::DataLoader& m_dataLoader;
    std::vector<std::string> m_homeAddress;
};

}//namespace se

void isNetworkConnected();

#endif
