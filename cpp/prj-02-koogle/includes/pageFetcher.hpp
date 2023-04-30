#ifndef PAGE_FETCHER
#define PAGE_FETCHER

#include <unordered_set>
#include <queue>
#include <atomic>

#include "crawlerIF.hpp"
#include "analyzPage.hpp"


namespace se{//Search Engine

class PageFetcher
{
public:
    explicit PageFetcher(se::CrawlerIF & crawler);
    PageFetcher(PageFetcher const& other) = default;
    PageFetcher& operator=(PageFetcher const& other) = default;
    virtual ~PageFetcher() = default;

    void startDownlaod();

private:
    se::CrawlerIF& m_crawler;
    std::atomic_bool m_newUrlInQueue;
    std::atomic_int m_activesTreads;
};

}//namespace se

#endif
