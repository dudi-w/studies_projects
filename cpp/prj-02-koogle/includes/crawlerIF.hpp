#ifndef CRAWLER_IF_HPP
#define CRAWLER_IF_HPP

#include <string>
#include <vector>

namespace se{//Search Engine

class CrawlerIF
{
public:
    virtual ~CrawlerIF() = default;

    virtual void startCrawling() = 0;
    virtual void insertInQueue(std::vector<std::string> const& links) = 0;
};

}//namespace se

#endif
