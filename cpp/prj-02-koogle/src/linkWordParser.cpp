#include "linkParser.hpp"
#include "wordParser.hpp"
#include "linkWordParser.hpp"

se::LinkWordParser::LinkWordParser(LinkParser& linkParser, WordParser& wordParser)
: m_linkParser(linkParser)
, m_wordParser(wordParser)
{}

se::AnalyzPage se::LinkWordParser::pars(std::unique_ptr<se::Page> page){
    se::AnalyzPage words = m_wordParser.pars(std::make_unique<se::BasePage>(*page));
    se::AnalyzPage links = m_linkParser.pars(std::make_unique<se::BasePage>(*page));
    se::AnalyzPage analyzPage(*page);
    // se::AnalyzPage analyzPage(page->getSrc(), page->getBaseData());
    analyzPage.setLinks(links.getLinks());
    analyzPage.setWords(words.getWords());
    return analyzPage;
}
