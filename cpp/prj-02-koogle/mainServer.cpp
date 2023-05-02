#include <thread>

#include "matabase.hpp"
#include "crawler.hpp"
#include "smartQueryHandler.hpp"
#include "searchQueryFacilita.hpp"
#include "queryBuilderFactory.hpp"

int main()
{
    se::Matabase matabase;
    
    se::Crawler crawler(matabase);
    std::thread tr([&](){return crawler.startCrawling();});
    
    se::SmartQueryHandler queryHandler(matabase);
    se::QueryBuilderFactory querysIFfactory;
    se::QueryBuilder& queryBuilder = querysIFfactory.getQueryBuilder();
    se::SearchQueryFacilita queryFacilitator(queryHandler, queryBuilder);
    queryFacilitator.start();

    tr.join();

    return EXIT_SUCCESS;
}