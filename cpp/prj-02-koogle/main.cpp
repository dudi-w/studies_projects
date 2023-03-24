#include "parser.hpp"
#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"
#include "dataLoader.hpp"
#include "textUI.hpp"
#include "searchQueryHandler.hpp"
#include "crawler.hpp"

int main()
{
    se::SearchDB db;
    se::DataLoader loader("config.json", db);
    loader.startLaoding();
    se::SearchQueryHandler queryHandler(db);
    se::TextUI tui;

    while(true){
        auto request = tui.makeRequest();
        if(request==nullptr){break;}
        queryHandler.receivesRequest(*request);
        auto result = queryHandler.returnResult();
        tui.setAndShowResult(result);
    }
    return EXIT_SUCCESS;
}