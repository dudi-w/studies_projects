#ifndef CRAWLER_QUEUE_HPP
#define CRAWLER_QUEUE_HPP
// #pragma once

#include <string>
#include <unordered_set>
#include <queue>
#include <shared_mutex>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>

#include "configuration.hpp"
#include "analyzPage.hpp"

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
    std::string deQueue();

private:
    void srcURLValidation();
    bool ifBounded(std::string const& link) const;
    void extractSrcPrefix();
    void markURLAsActive(std::string const& link);
    bool waitCondition();

private:
    std::unordered_set<std::string> m_searchedLinks;
    std::queue<std::string> m_queue;
    std::vector<std::string> m_homeAddress;
    std::atomic<size_t> m_waiting;
    std::condition_variable m_cv;
    /*mutable*/ std::mutex m_mutexMode;
};

}//namespace se

#endif
