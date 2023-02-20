#ifndef BALL_HPP
#define BALL_HPP

#include "moveObject.hpp"

namespace gm{
    
class Ball : public MoveObject
{

public:
	Ball() = default;
	~Ball() = default;

    void drawObject(sf::RenderWindow window) const override;
	void move(gm::Collisions collisions) override;
    gm::Collisions checkScreenCollisions(sf::RenderWindow window) override;
    
private:
    sf::Vector2f m_direction;
};

} // namespace gm

#endif
