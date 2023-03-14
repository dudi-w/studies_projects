#include "../includes/ball.hpp"

gm::Ball::Ball(sf::Vector2f const& position ,sf::Texture const& texture)
: MoveObject(position ,texture)
, m_Movement(false)
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(position);
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
