#ifndef BEST_PLAYERS_HPP
#define BEST_PLAYERS_HPP

#include <map>
#include <string>
#include "object.hpp"
#include "textObject.hpp"
#include "resourcesManager.hpp"
#include "player.hpp"

namespace gm{

class BestPlayers : public Object 
{
public:
    explicit BestPlayers(std::string const& fileName ,gm::ResourcesManager const& ResourcesManager);
    BestPlayers(BestPlayers const& other) = default;
    BestPlayers& operator=(BestPlayers const& other) = default;
    ~BestPlayers();

	sf::Drawable const& getDraw() const override;
    
    bool isModified() const;
    void manageHighScores(gm::Player const& player);

private:
    uint16_t getLowestScore() const;
    void removeLowestScore();
    void insertPlayer(uint16_t score, std::string const& player);
    void PrepareTextForDisplay();
    void loadFromFile();
    void unloadToFile() const;

private:
    std::string m_fileName;
    gm::TextObject m_showResults;
    bool m_modified;
    std::multimap<uint16_t, std::string> m_playersDB;
};

}//namespace gm

#endif
