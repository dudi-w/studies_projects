#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

#include "analyzPage.hpp"
#include "linkWordParser.hpp"
#include "crawlerIF.hpp"
#include "setDatabase.hpp"
#include "configuration.hpp"

namespace se{//Search Engine

class DataLoader
{
public:
    explicit DataLoader(std::string const& configurationFilePath, se::SetDB& searchDatabase);
    DataLoader(DataLoader const& other) = default;
    DataLoader& operator=(DataLoader const& other) = default;
    ~DataLoader() = default;

    void startLaoding();
    se::Configuration laodConfiguration(std::string const& configurationFilePath);
    void updatePage(AnalyzPage const& page);

private:
    se::SetDB& m_searchDatabase;
    se::WordParser m_wordParser;
    se::LinkParser m_linkParser;
    se::LinkWordParser m_parser;
    std::unique_ptr<CrawlerIF> m_crawler;
};

}//namespace se

void from_json(const nlohmann::json& j, se::Configuration& config);

#endif
