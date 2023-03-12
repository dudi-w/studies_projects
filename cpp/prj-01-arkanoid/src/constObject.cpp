#include "../includes/constObject.hpp"

gm::ConstObject::ConstObject(sf::Vector2f const& position ,sf::Texture const& texture ,uint16_t killScore, sf::Color color ,uint16_t life)
: SpriteObject(position ,texture)
, m_killScore(killScore)
, m_life(life)
{
    m_sprite.setColor(color);
}

void gm::ConstObject::setColor(sf::Color color)
{
    m_sprite.setColor(color);
}

// void gm::ConstObject::setColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha = (sf::Uint8)255U)
// {
    // m_sprite.setColor(sf::Color(red, green, blue, alpha));
// }

void gm::ConstObject::addLife()
{
    m_life.add(1);
}

void gm::ConstObject::subLife()
{
    m_life.sub(1);
}

// bool gm::ConstObject::isKill() const
// {
    // return m_life.isKill();
// }

uint16_t gm::ConstObject::killScore() const
{
    return m_killScore;
}