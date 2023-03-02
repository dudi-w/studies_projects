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
    BestPlayers(std::string const& fileName ,gm::ResourcesManager& ResourcesManager);
    BestPlayers(BestPlayers const& other) = default;
    BestPlayers& operator=(BestPlayers const& other) = default;
    ~BestPlayers();

	virtual sf::Drawable const& getDraw() const override final;
    
    void manageHighScores(gm::Player const& player);

private:
    uint16_t getLowestScore() const;
    void removeLowestScore();
    void insertPlayer(uint16_t score, std::string const& player);
    void PrepareTextForDisplay();
    void loadFromFile();
    void unloadToFile();
    bool isModified();

private:
    std::string m_fileName;
    gm::TextObject m_showResults;
    bool m_modified;
    std::multimap<uint16_t, std::string> m_playersDB;
};

}//namespace gm

#endif
