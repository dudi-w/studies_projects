#include "getHTTP2.hpp"
#include "parser.hpp"
#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"
#include "getHTTP2.hpp"
#include "dataLoader.hpp"
#include "textUI.hpp"
#include "searchQueryHandler.hpp"
// #include <malloc.h>

// #include <fstream>
// #include <iostream>
// #include <stdlib.h>
// #include <string>

int main()
{
    // std::string const url = "https://harrypotter.fandom.com/wiki/Main_Page";
    // se::WordParser wordParsr;
    // se::LinkParser linkParsr;
    // se::LinkWordParser wordLinkParsr(linkParsr ,wordParsr);
    se::SearchDB db;
    se::DataLoader loader("config.json", db);
    std::cout<<"start laoding"<<std::endl;
    loader.startLaoding();
    se::SearchQueryHandler queryHandler(db);
    se::TextUI tui;

    while(true){
        auto request = tui.makeRequest();
        queryHandler.receivesRequest(*request);
        auto result = queryHandler.returnResult();
        tui.setAndShowResult(*result);
    }
    
    // auto resulte = db.searchWord("harry");
    // auto it = resulte.begin();
    // while(it != resulte.end()){
        // std::cout<<it->first<<'\t'<<it->second<<'\n';
        // ++it;
    // }
    // 
// 
    
    // auto basePage = getHTTPpage(url);
    // auto page = std::make_unique<se::BasePage>(basePage);
    // test(page->getBaseData());
    // auto pp = wordLinkParsr.pars(std::move(page));
    // std::cout<<pp.getLinks().size()<<std::endl;
    // std::cout<<pp.getWords().size()<<std::endl;
    return EXIT_SUCCESS;
}