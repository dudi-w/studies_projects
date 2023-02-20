#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

namespace gm{ // game namespace
    
class Object
{

public:
	Object(size ,position ,texture) = default;
	virtual ~Object() = default;

	virtual void drawObject(sf::RenderWindow window) const = 0;

protected:
	sf::Sprite m_sprite;
};

} // namespace gm

#endif
