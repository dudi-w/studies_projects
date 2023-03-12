#ifndef INDESTRUCT_BRICKS_HPP
#define INDESTRUCT_BRICKS_HPP

#include "constObject.hpp"

namespace gm{

class IndestructBrick : public ConstObject
{
public:
    using ConstObject::ConstObject;
    IndestructBrick& operator=(IndestructBrick const& other) = default;
	~IndestructBrick() = default;

    bool isKill() const override;
};

}// namespace gm

inline bool gm::IndestructBrick::isKill() const
{
    return false;
}

#endif
