#ifndef SEARCH_DB_HPP
#define SEARCH_DB_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace se{//Search Engine

class SearchDB
{
public:
    SearchDB() = default;
    SearchDB(SearchDB const& other) = default;
    SearchDB& operator=(SearchDB const& other) = default;
    ~SearchDB() {std::cout<<"~SearchDB\n"<<std::endl;}//

    void log() const;
    std::unordered_map<std::string ,size_t> const& searchWord(std::string const& word) const;
    size_t linkOccurrenceCount(std::string const& link1, std::string const& link2) const;
    void insertLinks(std::string const& srclink, std::vector<std::string> const& links);
    void insertLink(std::string const& srcLink, std::string const& link);
    void insertWords(std::string const& srcLink, std::vector<std::string> const& words);
    bool wordExis(std::string const& word) const;
    bool wordAndLinkExis(std::string const& word, std::string const& link) const;


private:
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_wordsIndex;
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_linksMap;
};

}//namespace se

#endif
