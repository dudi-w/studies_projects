#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <memory>
#include "spriteObject.hpp"
#include "GMenum.hpp"

namespace gm{

class Collision
{
public:
    virtual ~Collision() = default;

    virtual void doCollision() const = 0;
};

}

#endif
