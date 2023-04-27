#ifndef CRAWLER_QUEUE_HPP
#define CRAWLER_QUEUE_HPP

#include <string>
#include <unordered_set>
#include <queue>
#include <shared_mutex>
#include <mutex>

#include "configuration.hpp"
#include "analyzPage.hpp"

namespace se{//Search Engine

class CrawlerQueue
{
public:
    explicit CrawlerQueue(std::vector<std::string> const& srcURL, size_t maxPages, bool bounded);
    explicit CrawlerQueue(se::Configuration const& configuration);
    CrawlerQueue(CrawlerQueue const& other) = default;
    CrawlerQueue& operator=(CrawlerQueue const& other) = default;
    ~CrawlerQueue() = default;

    void inQueue(std::vector<std::string> const& links);
    void inQueue(std::string const& links);
    std::string deQueue();
    void markURLAsSearched(std::string const& link);

private:
    void srcURLValidation();
    bool ifBounded(std::string const& link) const;
    void extractSrcPrefix();

private:
    struct Configuration{
    std::vector<std::string> srcURL;
    size_t maxPages;
    bool bounded;
    } m_configuration;
    std::unordered_set<std::string> m_searchedLinks;
    std::queue<std::string> m_queue;
    std::vector<std::string> m_homeAddress;
    mutable std::shared_mutex m_mutexMode;
};

}//namespace se

#endif

