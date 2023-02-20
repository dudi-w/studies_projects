#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "moveObject.hpp"

namespace gm{
    
class Flatform : public MoveObject
{

public:
	Flatform() = default;
	~Flatform() = default;

    void drawObject(sf::RenderWindow window) const override;
	void move(gm::Collisions collisions) override;
    gm::Collisions checkScreenCollisions(sf::RenderWindow window) override;
    
private:
    sf::Vector2f m_direction;
};

} // namespace gm

#endif
