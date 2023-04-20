#include "matabase.hpp"
#include "crawler.hpp"
#include "smartQueryHandler.hpp"
#include "searchQueryFacilita.hpp"
#include "queryIFfactory.hpp"

int main()
{
    se::Matabase matabase;
    {
    se::Crawler crawler("config.json", matabase);
    crawler.startCrawling();
    }

    se::SmartQueryHandler queryHandler(matabase);
    se::QueryIFfactory querysIFfactory;
    se::QuerysIF& queryIF = querysIFfactory.getIF();
    se::SearchQueryFacilita queryFacilitator(queryHandler, queryIF);
    queryFacilitator.strart();

    return EXIT_SUCCESS;
}