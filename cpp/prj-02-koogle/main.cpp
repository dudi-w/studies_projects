#include "matabase.hpp"
#include "crawler.hpp"
// #include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "server.hpp"
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
    se::QuerysIF& UIF = querysIFfactory.getIF();
    se::Server server(queryHandler, UIF);
    server.strart();

    return EXIT_SUCCESS;
}