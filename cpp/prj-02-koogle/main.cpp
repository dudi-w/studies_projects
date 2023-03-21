#include "getHTTP2.hpp"
#include "parser.hpp"
#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"
#include "getHTTP2.hpp"
#include "dataLoader.hpp"
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
    std::cout<<"loader"<<std::endl;
    loader.startLaoding();

    
    // auto basePage = getHTTPpage(url);
    // auto page = std::make_unique<se::BasePage>(basePage);
    // test(page->getBaseData());
    // auto pp = wordLinkParsr.pars(std::move(page));
    // std::cout<<pp.getLinks().size()<<std::endl;
    // std::cout<<pp.getWords().size()<<std::endl;
    return EXIT_SUCCESS;
}