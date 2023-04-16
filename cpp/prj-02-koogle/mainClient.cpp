#include "clientQueryHandler.hpp"
#include "server.hpp"
#include "textUI.hpp"

int main()
{
    se::ClientQueryHandler queryHandler;
    se::TextUI TUI;
    se::Server server(queryHandler, TUI);
    server.strart();

    return EXIT_SUCCESS;
}