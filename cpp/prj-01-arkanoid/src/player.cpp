#include "../includes/player.hpp"

gm::Player::Player(uint16_t life)
: m_firstLife(life)
, m_life(m_firstLife)
, m_score(0)
{}

void gm::Player::setName(std::string const& name)
{
    m_name = name;
}

std::string const& gm::Player::getName() const
{
    return m_name;
}

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

void gm::Player::restart()
{
    m_life = gm::Life(m_firstLife);
    m_score = gm::Life(0);
}
