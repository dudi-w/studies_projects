#ifndef SEARCH_DB_HPP
#define SEARCH_DB_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <shared_mutex>

#include "safeUnorderedTable.hpp"
#include "setDatabase.hpp"
#include "getDatabase.hpp"

namespace se{//Search Engine

using StrC = std::string const&;
using MyMap = se::SafeUnorderedTable<std::string, std::string, size_t>;

class Matabase : public SetDB , public GetDB
{
public:
    Matabase() = default;
    Matabase(Matabase const& other) = delete;
    Matabase& operator=(Matabase const& other) = delete;
    virtual ~Matabase() = default;

    virtual std::unordered_map<std::string ,size_t> getLinkOfWord(StrC word) const override;
    virtual size_t getLinkOccurrenceCount(StrC link1, StrC link2) const override;
    virtual void insertLinks(StrC srclink, std::vector<std::string> const& links) override;
    virtual void insertWords(StrC srcLink, std::vector<std::string> const& words) override;
    virtual void log() const override;
    virtual bool wordExis(StrC word) const override;
    bool wordAndLinkExis(StrC word, StrC link) const;

private:
    virtual void insertLink(StrC srcLink, StrC link) override;

private:
    se::MyMap m_safeWordsIndex;
    se::MyMap m_safeLinksMap;
};

}//namespace se

#endif
