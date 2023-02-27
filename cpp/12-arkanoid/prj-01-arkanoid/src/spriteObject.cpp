#include "../includes/spriteObject.hpp"

gm::SpriteObject::SpriteObject(sf::Vector2f position ,sf::Texture& texture)
: m_sprite(texture)
{
	m_sprite.setPosition(position);
}

sf::Drawable const& gm::SpriteObject::getDraw() const
{
	return m_sprite;
}

sf::Sprite& gm::SpriteObject::setShip()
{
	return m_sprite;
}
