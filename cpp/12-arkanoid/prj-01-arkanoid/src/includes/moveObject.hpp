#ifndef MOVE_OBJECT_HPP
#define MOVE_OBJECT_HPP

#include "object.hpp"
#include "GMenum.hpp"

namespace gm{
    
class MoveObject : public Object
{

public:
	MoveObject() = default;
	virtual ~MoveObject() = default;

    virtual void drawObject0(sf::RenderWindow window) const = 0;
	virtual void move(gm::Collisions collisions) = 0;
    virtual gm::Collisions checkScreenCollisions(sf::RenderWindow window) = 0;

protected:
    sf::Vector2f m_direction;
};

} // namespace gm

#endif
