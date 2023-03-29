#include <fstream>
#include <nlohmann/json.hpp>

#include "dataLoader.hpp"
#include "crawler.hpp"

se::DataLoader::DataLoader(std::string const& configurationFilePath, se::SetDB& searchDatabase)
: m_searchDatabase(searchDatabase)
, m_parser(m_linkParser, m_wordParser)
{
    auto& configuration = se::Configuration::getInstens(configurationFilePath);
    m_crawler =  std::make_unique<se::Crawler>(*this, configuration);
}

void se::DataLoader::startLaoding()
{
    m_crawler->startCrawling();
    m_searchDatabase.log();
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
