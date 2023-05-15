#ifndef GET_DB_HPP
#define GET_DB_HPP

#include <string>
#include <vector>
#include <unordered_map>

namespace se{//Search Engine
using LinkVec = std::vector<std::pair<std::string, float>>;

class GetDB 
{
public:
    virtual ~GetDB() = default;

    virtual se::LinkVec getLinkOfWord(std::string const& word) const = 0;
    virtual size_t getLinkOccurrenceCount(std::string const& link1, std::string const& link2) const = 0;
    virtual bool wordExis(std::string const& word) const = 0;
};

}//namespace se

#endif
