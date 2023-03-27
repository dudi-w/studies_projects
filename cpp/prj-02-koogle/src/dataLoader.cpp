#include <fstream>
#include <nlohmann/json.hpp>

#include "dataLoader.hpp"
#include "crawler.hpp"

se::DataLoader::DataLoader(std::string const& configurationFilePath, se::SetDB& searchDatabase)
: m_searchDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
{
    se::Configuration configuration = laodConfiguration(configurationFilePath);
    m_crawler =  std::make_unique<se::Crawler>(*this, configuration);
}

void se::DataLoader::startLaoding()
{
    m_crawler->startCrawling();
    std::cout<<"\033[3;32mEnd Crawling\033[0m\n";
    m_searchDatabase.log();
}

void se::DataLoader::setCrawler(std::unique_ptr<CrawlerIF> crawler)
{
    m_crawler = std::move(crawler);
}

se::Configuration se::DataLoader::laodConfiguration(std::string const& configurationFilePath)
{
    try{
        std::ifstream input_file(configurationFilePath);
        nlohmann::json j;
        input_file >> j;
        se::Configuration config;
        from_json(j, config);
        return config;
    }
    catch(const nlohmann::json::exception& e)
    {
        throw std::runtime_error("load configuration file failed ,check yuor configuration file");
    }  
}

void se::DataLoader::updatePage(AnalyzPage const& page)
{
    auto parsPage = m_parser.pars(std::make_unique<se::BasePage>(page));
    auto srcPage = parsPage.getSrc();
    auto links = parsPage.getLinks();
    auto words = parsPage.getWords();
    m_searchDatabase.insertLinks(srcPage, links);
    m_searchDatabase.insertWords(srcPage, words);
    m_crawler->insertInQueue(links);
}

void from_json(const nlohmann::json& j, se::Configuration& config)
{
    j.at("srcURL").get_to(config.srcURL);
    j.at("maxPages").get_to(config.maxPages);
    j.at("maxDepth").get_to(config.maxDepth);
    j.at("bounded").get_to(config.bounded);
}
