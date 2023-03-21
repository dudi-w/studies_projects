#ifndef PARSE_PAGE_HPP
#define PARSE_PAGE_HPP

#include <vector>

#include "basePage.hpp"
// #include "parser.hpp"

namespace se{//Search Engine

class AnalyzPage : public BasePage
{
public:
    using BasePage::BasePage;
    AnalyzPage(BasePage const& other);
    AnalyzPage& operator=(AnalyzPage const& other) = default;
    ~AnalyzPage() = default;

    // friend class se::Parser;

    std::vector<std::string> const& getLinks() const;
    std::vector<std::string> const& getWords() const;
    void setLinks(std::vector<std::string> const& links);
    void setWords(std::vector<std::string> const& words);
    // friend void setLinks(se::Parser* parser, AnalyzPage& self, std::vector<std::string> links) {self.m_links = links;}
    // friend void setWords(se::Parser const& parser, AnalyzPage& self, std::vector<std::string> words) {self.m_words = words;}

private:
    std::vector<std::string> m_links;
    std::vector<std::string> m_words;
};

}//namespace se

#endif
