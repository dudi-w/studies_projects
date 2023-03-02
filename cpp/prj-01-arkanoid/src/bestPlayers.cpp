#include <fstream>
#include <filesystem>
#include "../includes/bestPlayers.hpp"

using rs = gm::ResourcesManager::Resource;

gm::BestPlayers::BestPlayers(std::string  const& fileName, gm::ResourcesManager const& resourcesManager)
: m_fileName(fileName)
, m_showResults(10,10)
, m_modified(true)
{
    m_showResults.set_character_size(50);
    sf::Color color(sf::Color::Black);
    m_showResults.set_Color(color);
    m_showResults.set_font(resourcesManager.getFont(rs::font3));

    loadFromFile();
    PrepareTextForDisplay();
}

gm::BestPlayers::~BestPlayers()
{
    unloadToFile();
}

sf::Drawable const& gm::BestPlayers::getDraw() const
{
    return m_showResults.getDraw();
}

void gm::BestPlayers::PrepareTextForDisplay()
{
    std::string text("the ten top players :\n");
    auto it = m_playersDB.crbegin();
    while(it != m_playersDB.crend()){
        text+="\t"+it->second + " : ";
        text+=std::to_string(it->first)+".\n";
        ++it;
    }
    m_showResults.setMessage(text);
}

void gm::BestPlayers::loadFromFile()
{
    std::string name;
    std::string score;
    std::fstream fs;
    m_playersDB.clear();
    fs.clear();

    auto path = std::filesystem::path(m_fileName);
    if(std::filesystem::exists(path)){
        fs.open(m_fileName, std::ios::in);
        while(std::getline(fs , name ,',') && std::getline(fs , score,'\n')){
            m_playersDB.insert({stoi(score) ,name});
            name.clear();
            score.clear();
        }
    }
    fs.close();
}

void gm::BestPlayers::unloadToFile() const
{
    if(!isModified()){
        return;
    }
    std::fstream fs;
    fs.clear();
    fs.open(m_fileName, std::ios::out);

    auto it = m_playersDB.cbegin();
    while(it != m_playersDB.cend() && fs){
        fs<< it->second;
        fs<< ",";
        fs<< std::to_string(it->first);
        fs<<"\n";
        ++it;
    }
    fs.close();
}

uint16_t gm::BestPlayers::getLowestScore() const
{
    return m_playersDB.cbegin()->first;
}

void gm::BestPlayers::removeLowestScore()
{
    if(!m_playersDB.size()){
        return;
    }
    auto it = m_playersDB.cbegin();
    it = m_playersDB.erase(it);

    m_modified = true;
}

void gm::BestPlayers::insertPlayer(uint16_t score, std::string const& player)
{
    m_playersDB.insert({score,player});
    m_modified = true;
}

bool gm::BestPlayers::isModified() const
{
    return m_modified;
}

void gm::BestPlayers::manageHighScores(gm::Player const& player)
{
    if(m_playersDB.size()>=10 && player.getScore() > getLowestScore()){
        removeLowestScore();
        insertPlayer(player.getScore(), player.getName());
    }else if(m_playersDB.size()<10){
        insertPlayer(player.getScore(), player.getName());
    }
    PrepareTextForDisplay();
}
