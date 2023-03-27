#include "parser.hpp"
#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"
#include "dataLoader.hpp"
#include "textUI.hpp"
#include "smartQueryHandler.hpp"
#include "crawler.hpp"

int main()
{
    se::SearchDB db;
    se::DataLoader loader("config.json", db);
    // se::DataLoader loader("home/mefathim-tech-11/s06.dudivi/cpp/prj-02-koogle/config.json", db);
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