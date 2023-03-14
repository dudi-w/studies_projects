#include "../includes/spriteObject.hpp"

gm::SpriteObject::SpriteObject(sf::Vector2f const& position ,sf::Texture const& texture)
: m_sprite(texture)
{
	m_sprite.setPosition(position);
}

sf::Drawable const& gm::SpriteObject::getDraw() const
{
	return m_sprite;
}

sf::FloatRect gm::SpriteObject::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

