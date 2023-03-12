#ifndef BALL_BRICK_COLLISION
#define BALL_BRICK_COLLISION

#include "collisions.hpp"
#include "constObject.hpp"
#include "ball.hpp"

namespace gm{

class BallBrickCollision : public Collision
{
public:
    explicit BallBrickCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::ConstObject> brick ,gm::CollisionSide side);
    BallBrickCollision(BallBrickCollision const & other) = default;
    BallBrickCollision& operator=(BallBrickCollision const & other) = default;
    ~BallBrickCollision() = default;

    uint16_t doCollision() const override;

private:
    std::shared_ptr<gm::Ball> m_ball;
    std::shared_ptr<gm::ConstObject> m_brick;
    gm::CollisionSide m_side; //the collision side
};

}// namespace gm

#endif
