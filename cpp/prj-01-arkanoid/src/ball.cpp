#include "../includes/ball.hpp"

gm::Ball::Ball(sf::Vector2f const& position ,sf::Texture& texture)
: MoveObject(position ,texture)
, m_Movement(false)
{
	setShip().setOrigin(setShip().getGlobalBounds().width/2,setShip().getGlobalBounds().height/2);
	setShip().setPosition(position);
}

void gm::Ball::move(sf::Vector2f direction)
{
	
	if(direction.x != 0 || direction.y != 0 || !isMoved()){
		m_direction = direction;
	}
	m_sprite.move(m_direction);

	if(isMoved()){
		m_sprite.rotate(20);
	}
	return;
}

void gm::Ball::reset()
{
    m_direction = sf::Vector2f(0,0);
    m_sprite.setPosition(m_firstPosition);
	m_Movement = false;
}

bool gm::Ball::isMoved() const
{
	return m_Movement;
}

void gm::Ball::startMove()
{
	m_Movement = true;
}

sf::Clock const& gm::Ball::time() const
{
	return m_time;
}

void gm::Ball::resetTime()
{
	m_time.restart();
}