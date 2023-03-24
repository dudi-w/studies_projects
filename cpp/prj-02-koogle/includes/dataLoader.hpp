#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

#include "analyzPage.hpp"
#include "linkWordParser.hpp"
#include "crawlerIF.hpp"
#include "searchDatabase.hpp"
#include "configuration.hpp"

namespace se{//Search Engine

class DataLoader
{
public:
    explicit DataLoader(std::string const& configurationFilePath, SearchDB& searchDatabase);
    DataLoader(DataLoader const& other) = default;
    DataLoader& operator=(DataLoader const& other) = default;
    ~DataLoader() {std::cout<<"~DataLoader\n"<<std::endl;}

    void startLaoding();
    se::Configuration laodConfiguration(std::string const& configurationFilePath);
    void setCrawler(std::unique_ptr<CrawlerIF> crawler);
    void updatePage(AnalyzPage const& page);

private:
    se::SearchDB& m_searchDatabase;
    se::WordParser m_wordParser;
    se::LinkParser m_linkParser;
    se::LinkWordParser m_parser;
    std::unique_ptr<CrawlerIF> m_crawler;
};

}//namespace se

void from_json(const nlohmann::json& j, se::Configuration& config);

#endif
