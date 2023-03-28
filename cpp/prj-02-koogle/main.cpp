#include "parser.hpp"
#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"
#include "dataLoader.hpp"
#include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "crawler.hpp"
#include "searchDatabase.hpp"


int main()
{
    se::SearchDB db;
    se::DataLoader loader("config.json", db);
    loader.startLaoding();
    se::SmartQueryHandler queryHandler(db);
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