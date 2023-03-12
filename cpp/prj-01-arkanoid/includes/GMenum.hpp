#ifndef GM_ENUM_HPP
#define GM_ENUM_HPP

#include <unordered_map>

namespace gm{
    
enum class CollisionSide : int8_t
{
    noCollisions,
    Right,
    Left,
    Up,
    Bottom
};

enum class Type : int8_t
{
    noType,
    brickType1,
    brickType2,
    brickType3,
    brickType4,
    brickType5,
    brickType6,
    brickType7,
    brickType8,
    brickType9,
    brickType10
};

}// namespace gm

#endif
