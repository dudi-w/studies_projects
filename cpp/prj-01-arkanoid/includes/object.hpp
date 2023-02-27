#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

namespace gm{ // game namespace
    
class Object
{
public:
	virtual ~Object() = default;

	virtual sf::Drawable const& getDraw() const = 0;
};

} // namespace gm

#endif
