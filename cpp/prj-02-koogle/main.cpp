#include "matabase.hpp"
#include "dataLoader.hpp"
#include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "server.hpp"

int main()
{
    se::Matabase db;
    se::DataLoader loader("config.json", db);
    loader.startLaoding();

    se::SmartQueryHandler queryHandler(db);
    se::TextUI tui;
    se::Server server(queryHandler, tui);
    server.strart();

    return EXIT_SUCCESS;
}