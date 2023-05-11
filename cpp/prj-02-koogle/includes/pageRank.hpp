#ifndef PAGE_RANK_HPP
#define PAGE_RANK_HPP

#include <string>
#include <unordered_map>

namespace se{

using MyMap = std::unordered_map<std::string ,std::unordered_map<std::string ,size_t>>;

class PageRank
{
public:
    PageRank() = default;
    PageRank(PageRank const& other) = default;
    PageRank& operator=(PageRank const& other) = default;
    ~PageRank() = default;

    void reCalculatePageRank(se::MyMap linksMap);
    float getRank(std::string const& link) const;

private:
    std::unordered_map<std::string, float> m_scoreMap;
};

}// namespace se

#endif
