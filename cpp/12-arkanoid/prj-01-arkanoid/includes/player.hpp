#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "life.hpp"

namespace gm{

class Player
{
public:
    explicit Player(std::string name ,uint16_t life = 3);
    Player(Player const& other) = default;
    Player& operator=(Player const& other) = default;
    ~Player() = default;

    uint16_t getLife() const;
    bool isKill() const;
    void addLife();
    void subLife();
    
    uint16_t getScore() const;
    void addScore(uint16_t n);
    void subScore(uint16_t n);

private:
    std::string m_name;
    gm::Life m_life;
    gm::Life m_score;
};

}//namespace gm

#endif
