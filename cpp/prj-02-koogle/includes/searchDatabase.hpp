#ifndef SEARCH_DB_HPP
#define SEARCH_DB_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "setDatabase.hpp"
#include "getDatabase.hpp"


namespace se{//Search Engine

class SearchDB : public SetDB , public GetDB
{
public:
    SearchDB() = default;
    SearchDB(SearchDB const& other) = default;
    SearchDB& operator=(SearchDB const& other) = default;
    virtual ~SearchDB() = default;

    virtual std::unordered_map<std::string ,size_t> const& getLinkOfWord(std::string const& word) const override;
    virtual size_t getLinkOccurrenceCount(std::string const& link1, std::string const& link2) const override;
    virtual void insertLinks(std::string const& srclink, std::vector<std::string> const& links) override;
    virtual void insertLink(std::string const& srcLink, std::string const& link) override;
    virtual void insertWords(std::string const& srcLink, std::vector<std::string> const& words) override;
    virtual void log() const override;
    
    virtual bool wordExis(std::string const& word) const override;
    bool wordAndLinkExis(std::string const& word, std::string const& link) const;

private:
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_wordsIndex;
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_linksMap;
};

}//namespace se

#endif
