#ifndef SPRITE_OBJECT_HPP
#define SPRITE_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "object.hpp"


namespace gm{ // game namespace

class SpriteObject : public Object
{
public:
	explicit SpriteObject(sf::Vector2f const& position ,sf::Texture const& texture);
	SpriteObject(SpriteObject const& other) = default;
    SpriteObject& operator=(SpriteObject const& other) = default;
	virtual ~SpriteObject() = default;

	virtual sf::Drawable const& getDraw() const override final;
	virtual sf::FloatRect getGlobalBounds() const final;

protected:
    sf::Sprite m_sprite;
};

} // namespace gm

#endif
