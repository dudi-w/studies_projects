#include "analyzPage.hpp"
#include "parser.hpp"

se::AnalyzPage::AnalyzPage(BasePage const& other)
: BasePage(other)
{}

std::vector<std::string> const& se::AnalyzPage::getLinks() const
{
    return m_links;
}

std::vector<std::string> const& se::AnalyzPage::getWords() const
{
    return m_words;
}

void se::AnalyzPage::setLinks(std::vector<std::string> const& links)
{
    m_links = links;
}

void se::AnalyzPage::setWords(std::vector<std::string> const& words)
{
    m_words = words;
}


// void setLinks(se::Parser& parser, se::AnalyzPage& self, std::vector<std::string> links)
// {
//     self.
// }

// void setWords(se::Parser const& parser, std::vector<std::string> links)
// {

// }

