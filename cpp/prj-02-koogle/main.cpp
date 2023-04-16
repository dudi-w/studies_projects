#include "matabase.hpp"
#include "crawler.hpp"
#include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "server.hpp"

int main()
{
    se::Matabase matabase;
    {
    se::Crawler crawler("config.json", matabase);
    crawler.startCrawling();
    }

    se::SmartQueryHandler queryHandler(matabase);
    se::TextUI TUI;
    se::Server server(queryHandler, TUI);
    server.strart();

    return EXIT_SUCCESS;
}