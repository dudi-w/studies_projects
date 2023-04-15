#include "matabase.hpp"
#include "crawler.hpp"
#include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "server.hpp"

int main()
{
    se::Matabase db;
    {
    se::Crawler crawler("config.json", db);
    crawler.startCrawling();
    }

    se::SmartQueryHandler queryHandler(db);
    se::TextUI tui;
    se::Server server(queryHandler, tui);
    server.strart();

    return EXIT_SUCCESS;
}