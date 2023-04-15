#ifndef SEARCH_DB_HPP
#define SEARCH_DB_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "setDatabase.hpp"
#include "getDatabase.hpp"

using strC = std::string const&;
namespace se{//Search Engine

class Matabase : public SetDB , public GetDB
{
public:
    Matabase() = default;
    Matabase(Matabase const& other) = default;
    Matabase& operator=(Matabase const& other) = default;
    virtual ~Matabase() = default;

    virtual std::unordered_map<std::string ,size_t> const& getLinkOfWord(strC word) const override;
    virtual size_t getLinkOccurrenceCount(strC link1, strC link2) const override;
    virtual void insertLinks(strC srclink, std::vector<std::string> const& links) override;
    virtual void insertLink(strC srcLink, strC link) override;
    virtual void insertWords(strC srcLink, std::vector<std::string> const& words) override;
    virtual void log() const override;
    
    virtual bool wordExis(strC word) const override;
    bool wordAndLinkExis(strC word, strC link) const;

private:
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_wordsIndex;
    std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>> m_linksMap;
};

}//namespace se

#endif
