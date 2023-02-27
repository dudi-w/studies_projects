#ifndef BALL_HPP
#define BALL_HPP

#include "moveObject.hpp"

namespace gm{
    
class Ball : public MoveObject
{

public:
	explicit Ball(sf::Vector2f position ,sf::Texture& texture);
	Ball& operator=(Ball const& other) = default;
	~Ball() = default;

	void move(sf::Vector2f direction = sf::Vector2f(0,0)) override;
	void reset() override;
	bool isMoved() const;
	void startMove();
	sf::Clock const& time() const;
	void resetTime();

private:
	bool m_Movement;
	sf::Clock m_time;
};

} // namespace gm

#endif
