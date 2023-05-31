#include "matabase.hpp"
#include "crawler.hpp"
#include "smartQueryHandler.hpp"
#include "queryBuilderFactory.hpp"
#include "queryProcessor.hpp"

int main()
{
    se::Matabase matabase;
    
    se::Crawler crawler(matabase);

    se::SmartQueryHandler searcher(matabase);
    se::QueryBuilderFactory querysIFfactory;
    se::QueryBuilder& queryBuilder = querysIFfactory.getQueryBuilder();
    se::QueryProcessor queryFacilitator(searcher, queryBuilder);
    queryFacilitator.start();
    return EXIT_SUCCESS;
}