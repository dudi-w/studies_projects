#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "moveObject.hpp"

namespace gm{
    
class Platform : public MoveObject
{

public:
	using MoveObject::MoveObject;
	Platform& operator=(Platform const& other) = default;
	~Platform() = default;
	
	void move(sf::Vector2f direction = sf::Vector2f(0,0)) override;
	void reset() override;
};

} // namespace gm

#endif
