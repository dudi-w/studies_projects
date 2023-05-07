#ifndef CRAWLER_QUEUE_HPP
#define CRAWLER_QUEUE_HPP

#include <string>

#include "configuration.hpp"
#include "analyzPage.hpp"
#include "safeQueue.hpp"
#include "safeUnorderedSet.hpp"

namespace se{//Search Engine

class CrawlerQueue
{
public:
    CrawlerQueue();
    explicit CrawlerQueue(std::vector<std::string> const& srcURL, size_t maxPages, bool bounded) = delete;
    explicit CrawlerQueue(se::Configuration const& configuration) = delete;
    CrawlerQueue(CrawlerQueue const& other) = default;
    CrawlerQueue& operator=(CrawlerQueue const& other) = default;
    ~CrawlerQueue() = default;

    void inQueue(std::vector<std::string> const& links);
    void inQueue(std::string const& links);
    void inQueue(std::string && link);
    std::string deQueue();

private:
    void srcURLValidation();
    bool ifBounded(std::string const& link) const;
    void extractSrcPrefix();
    void logAsActive(std::string const& link);

private:
    se::SafeQueue<std::string> m_safeQueue;
    se::SafeUnorderedSet<std::string> m_activedLinks;
    std::vector<std::string> m_homeAddress;
};

}//namespace se

#endif
