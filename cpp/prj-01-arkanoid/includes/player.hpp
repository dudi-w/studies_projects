#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "life.hpp"

namespace gm{

class Player
{
public:
    explicit Player(uint16_t life = 3);
    Player(Player const& other) = default;
    Player& operator=(Player const& other) = default;
    ~Player() = default;
    
    void setName(std::string const& name);
    std::string const& getName() const;
    uint16_t getLife() const;
    bool isKill() const;
    void addLife();
    void subLife();
    uint16_t getScore() const;
    void addScore(uint16_t n);
    void subScore(uint16_t n);
    void restart();

private:
    uint16_t m_firstLife;
    gm::Life m_life;
    gm::Life m_score;
    std::string m_name;
};

}//namespace gm

#endif
