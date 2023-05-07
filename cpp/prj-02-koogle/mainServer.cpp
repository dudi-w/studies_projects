#include "matabase.hpp"
#include "crawler.hpp"
#include "smartQueryHandler.hpp"
#include "searchQueryFacilita.hpp"
#include "queryBuilderFactory.hpp"

int main()
{
    se::Matabase matabase;
    
    se::Crawler crawler(matabase);

    se::SmartQueryHandler queryHandler(matabase);
    se::QueryBuilderFactory querysIFfactory;
    se::QueryBuilder& queryBuilder = querysIFfactory.getQueryBuilder();
    se::SearchQueryFacilita queryFacilitator(queryHandler, queryBuilder);
    queryFacilitator.start();

    return EXIT_SUCCESS;
}