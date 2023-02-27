#include "../includes/platform.hpp"
#include "../includes/definitions.hpp"

void gm::Platform::move(sf::Vector2f direction)
{
	m_direction = direction;
    
    if(m_direction.x == 0  &&  m_direction.y == 0){
		return;
	}
	m_sprite.move(m_direction);
	return;
}

void gm::Platform::reset()
{
	m_direction = sf::Vector2f(0,0);
    m_sprite.setPosition(m_firstPosition);
}
