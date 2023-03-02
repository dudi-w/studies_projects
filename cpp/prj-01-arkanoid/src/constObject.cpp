#include "../includes/constObject.hpp"

gm::ConstObject::ConstObject(sf::Vector2f const& position ,sf::Texture const& texture ,gm::Score killScore ,uint16_t life)
: SpriteObject(position ,texture)
, m_killScore(killScore)
, m_life(life)
{}

void gm::ConstObject::addLife()
{
    m_life.add(1);
}

void gm::ConstObject::subLife()
{
    m_life.sub(1);
}

bool gm::ConstObject::isKill() const
{
    return m_life.isKill();
}

gm::Score gm::ConstObject::killScore() const
{
    return m_killScore;
}
