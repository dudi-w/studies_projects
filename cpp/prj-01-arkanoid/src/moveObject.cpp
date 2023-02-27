#include "../includes/moveObject.hpp"

gm::MoveObject::MoveObject(sf::Vector2f const& position ,sf::Texture& texture)
: SpriteObject(position ,texture)
, m_firstPosition(position)
{}

sf::Vector2f const& gm::MoveObject::getDirection() const
{
    return m_direction;
}

void gm::MoveObject::setDirection(sf::Vector2f const& direction)
{
    m_direction = direction;
}
