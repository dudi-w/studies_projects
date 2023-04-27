#include "matabase.hpp"
#include "crawler.hpp"
#include "smartQueryHandler.hpp"
#include "searchQueryFacilita.hpp"
#include "queryBuilderFactory.hpp"

#include <chrono>

int main()
{
    se::Matabase matabase;
    {
    se::Crawler crawler(matabase);
    crawler.startCrawling();
    }

    se::SmartQueryHandler queryHandler(matabase);
    se::QueryBuilderFactory querysIFfactory;
    se::QueryBuilder& queryIF = querysIFfactory.getQueryBuildre();
    se::SearchQueryFacilita queryFacilitator(queryHandler, queryIF);
    queryFacilitator.strart();

    return EXIT_SUCCESS;
}
