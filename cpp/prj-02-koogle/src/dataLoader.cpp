#include "dataLoader.hpp"

void from_json(const nlohmann::json& j, se::Configuration& config);

namespace se{class Crawler : public CrawlerIF{public: explicit Crawler(DataLoader& dataLoader, Configuration configuration); virtual void startCrawling() override; virtual void insertInQueue(std::vector<std::string> const& links) override;};}

se::DataLoader::DataLoader(std::string const& configurationFilePath, SearchDB& searchDatabase)
: m_searchDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
{
    se::Configuration configuration = laodConfiguration(configurationFilePath);
    // se::Crawler(*this, configuration);
    m_crawler =  std::make_unique<se::Crawler>(*this, configuration);
    // m_crawler = nullptr;
    std::cout<<"\033[3;32mTEST\033[0m\n";
}

void se::DataLoader::startLaoding()
{
    m_crawler->startCrawling();
    std::cout<<"\033[3;32mend Crawling\033[0m\n";
}

se::Configuration se::DataLoader::laodConfiguration(std::string const& configurationFilePath)
{
    try
    {
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
    auto parsPage =  m_parser.pars(std::make_unique<se::BasePage>(page));
    auto srcPage = parsPage.getSrc();
    auto links = parsPage.getLinks();
    auto words = parsPage.getWords();
    std::cout<<words.size()<<" "<< links.size()<<" "<< srcPage <<std::endl;
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
