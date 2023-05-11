#include <algorithm>
#include <iostream>

#include "pageRank.hpp"

std::unordered_map<std::string, float> calculatePageRank2(std::unordered_map<std::string, std::unordered_map<std::string, size_t>> const& linksMap);
std::unordered_map<std::string, float> calculatePageRank(se::MyMap const& linksMap)
{
    std::unordered_map<std::string, float> pageRank(linksMap.size());
    std::unordered_map<std::string, std::pair<float, size_t>> pageRankP(linksMap.size());
    
    for(auto const& link : linksMap){
        pageRank[link.first] = 1;
    }

    const size_t N = linksMap.size();//Total number of pages
    const float d = 0.85;//Damping factor, usually 0.85
    float gap = 1;
    float newGap = 0;

    while(gap != newGap){
        newGap = gap;
        std::unordered_map<std::string, float> newPageRank;
        
        for(auto const& linkSrc : pageRank){
            for(auto const& link : linksMap.at(linkSrc.first)){
                if(newPageRank.count(link.first)==1){
                    newPageRank[link.first] += linkSrc.second/linksMap.at(link.first).size();//?
                }else{
                    newPageRank[link.first] = linkSrc.second/linksMap.at(link.first).size();
                }
            }
        }
        for(auto const& link : newPageRank){
            pageRank[link.first] = ((1-d)/N) + (d*link.second); 
        }

        auto it = newPageRank.cbegin();
        gap = std::abs(it->second - pageRank[it->first]);
        // std::cout<<(it->second) - (pageRank[it->first])<<" "<<"gap = "<<gap<<" newPageRank = "<<it->first<<" "<<it->second<<"  pageRank = "<<pageRank[it->first]<<std::endl;
        
    }
    return pageRank;
}

void se::PageRank::reCalculatePageRank(se::MyMap linksMap)
{
    m_scoreMap = calculatePageRank(linksMap);
}

float se::PageRank::getRank(std::string const& link) const
{
    if(m_scoreMap.count(link)){
        return m_scoreMap.at(link);
    }else{
        return 0;//TODO epsilon - minimum rank (1-0.85)/m_scoreMap.size();
    }
}


#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, float> calculatePageRank2(std::unordered_map<std::string, std::unordered_map<std::string, size_t>> const& linksMap){
    // Initialize all page ranks to 1/N
    std::unordered_map<std::string, float> pageRanks;

    float initialRank = 1.0f / linksMap.size();
    for (auto const& [link , _]: linksMap) {
        pageRanks[link] = initialRank;
    }

    // Set damping factor and maximum iterations
    const float dampingFactor = 0.85f;
    const int maxIterations = 100;

    // Iterate to calculate page ranks
    for (int i = 0; i < maxIterations; i++) {
        std::unordered_map<std::string, float> newRanks;

        // Calculate the contribution of each incoming link to the new rank
        for (auto const& link : linksMap) {
            float newRank = 0.0f;
            for (auto const& incomingLink : link.second) {
                std::string incomingPage = incomingLink.first;
                size_t incomingCount = incomingLink.second;
                float incomingRank = pageRanks[incomingPage];
                newRank += incomingRank / incomingCount;
            }

            // Apply damping factor and store the new rank
            newRank = dampingFactor * newRank + (1.0f - dampingFactor) * initialRank;
            newRanks[link.first] = newRank;
        }

        // Update page ranks for the next iteration
        pageRanks = std::move(newRanks);
    }
    return pageRanks;
}
/*
int main() {
    // Example usage
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> linksMap = {
        {"A", {{"B", 1}, {"C", 1}}},
        {"B", {{"C", 1}}},
        {"C", {{"A", 1}}}
    };

    std::unordered_map<std::string, float> pageRanks = calculatePageRank(linksMap);

    // Print out the resulting page ranks
    for (auto const& pageRank : pageRanks) {
        std::cout << pageRank.first << " -> " << pageRank.second << std::endl;
    }

    return 0;
}
*/