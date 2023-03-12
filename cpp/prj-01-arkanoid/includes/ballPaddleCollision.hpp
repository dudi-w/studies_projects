#ifndef BALL_PADDLE_COLLISION
#define BALL_PADDLE_COLLISION

#include "collisions.hpp"
#include "platform.hpp"
#include "ball.hpp"

namespace gm{

class BallPaddleCollision : public Collision
{
public:
    explicit BallPaddleCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::Platform> paddle ,gm::CollisionSide side);
    BallPaddleCollision(BallPaddleCollision const & other) = default;
    BallPaddleCollision& operator=(BallPaddleCollision const & other) = default;
    ~BallPaddleCollision() = default;

    uint16_t doCollision() const override;

private:
    std::shared_ptr<gm::Ball> m_ball;
    std::shared_ptr<gm::Platform> m_paddle;
    gm::CollisionSide m_side; //the collision side
};

}// namespace gm

#endif
