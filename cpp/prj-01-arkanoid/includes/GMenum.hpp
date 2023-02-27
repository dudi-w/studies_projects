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

enum class Score : int8_t
{
    noScore = 0,
    brickType1 = 40,
};

static std::unordered_map<Score,int> scoreMap = {
    {gm::Score::noScore , 0},
    {gm::Score::brickType1 , 40}
};

}// namespace gm

#endif
