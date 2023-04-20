#include "clientQueryHandler.hpp"
#include "searchQueryFacilita.hpp"
#include "textUI.hpp"

int main()
{
    se::ClientQueryHandler queryHandler("127.0.0.1", 8080);
    se::TextUI TUI;
    se::SearchQueryFacilita queryFacilitator(queryHandler, TUI);
    queryFacilitator.strart();

    return EXIT_SUCCESS;
}