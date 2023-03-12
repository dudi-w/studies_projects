#ifndef BRICK_HPP
#define BRICK_HPP

#include "constObject.hpp"

namespace gm{

class Brick : public ConstObject
{
public:
    using ConstObject::ConstObject;
    Brick& operator=(Brick const& other) = default;
	~Brick() = default;

    bool isKill() const override;
};

}// namespace gm

inline bool gm::Brick::isKill() const
{
    return m_life.isKill();
}

#endif
