#ifndef BRICKS_HPP
#define BRICKS_HPP

#include "spriteObject.hpp"
#include "GMenum.hpp"
#include "life.hpp"

namespace gm{

class ConstObject : public SpriteObject
{
public:
    explicit ConstObject(sf::Vector2f position ,sf::Texture& texture ,gm::Score killScore ,uint16_t life = 1 );
    ConstObject(ConstObject const& other) = default;
    ConstObject& operator=(ConstObject const& other) = default;
	virtual ~ConstObject() = default;

    void addLife();
    void subLife();
    bool isKill() const;
    gm::Score killScore() const;

private:
    const gm::Score m_killScore;
    gm::Life m_life;

};

}// namespace gm

#endif
