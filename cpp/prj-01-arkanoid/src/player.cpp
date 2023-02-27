#include "../includes/player.hpp"

gm::Player::Player(std::string name ,uint16_t life)
: m_name(name)
, m_life(life)
, m_score(0)
{}

uint16_t gm::Player::getLife() const
{
    return m_life.getCount();
}

bool gm::Player::isKill() const
{
    return m_life.isKill();
}

void gm::Player::addLife()
{
    m_life.add(1);
}

void gm::Player::subLife()
{
    m_life.sub(1);
}

uint16_t gm::Player::getScore() const
{
    return m_score.getCount();
}

void gm::Player::addScore(uint16_t n)
{
    m_score.add(n);
}

void gm::Player::subScore(uint16_t n)
{
    m_score.sub(n);
}
