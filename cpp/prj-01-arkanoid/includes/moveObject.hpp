#ifndef MOVE_OBJECT_HPP
#define MOVE_OBJECT_HPP

#include "spriteObject.hpp"
#include "GMenum.hpp"

namespace gm{

class MoveObject : public SpriteObject
{
public:
    explicit MoveObject(sf::Vector2f position ,sf::Texture& texture);
    MoveObject(MoveObject const& other) = default;
    MoveObject& operator=(MoveObject const& other) = default;
	virtual ~MoveObject() = default;

	virtual void move(sf::Vector2f direction) = 0;
    virtual void reset() = 0;

    virtual void setDirection(sf::Vector2f const& direction) final;
    virtual sf::Vector2f const& getDirection() const final;

protected:
    sf::Vector2f m_direction;
    sf::Vector2f m_firstPosition;
};

} // namespace gm

#endif
