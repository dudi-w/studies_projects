#ifndef CONST_HPP
#define CONST_HPP

#include "spriteObject.hpp"
#include "GMenum.hpp"
#include "life.hpp"

namespace gm{

class ConstObject : public SpriteObject
{
public:
    explicit ConstObject(sf::Vector2f const& position ,sf::Texture const& texture ,uint16_t killScore, sf::Color color ,uint16_t life = 1 );
    ConstObject(ConstObject const& other) = default;
    ConstObject& operator=(ConstObject const& other) = default;
	virtual ~ConstObject() = default;

    void setColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha = (sf::Uint8)255U);
    void setColor(sf::Color color);
    void addLife();
    void subLife();
    uint16_t killScore() const;

    virtual bool isKill() const = 0;

protected:
    uint16_t m_killScore;
    gm::Life m_life;
};

}// namespace gm

#endif
