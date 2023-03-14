#ifndef BALL_LIMIT_COLLISION
#define BALL_LIMIT_COLLISION

#include "collisions.hpp"
#include "ball.hpp"
#include "platform.hpp"
#include "player.hpp"
#include "GMenum.hpp"

namespace gm{

class BallLimitCollision : public Collision
{
public:
    explicit BallLimitCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::Platform> paddle ,gm::Player& player, gm::CollisionSide side);
    BallLimitCollision(BallLimitCollision const & other) = default;
    BallLimitCollision& operator=(BallLimitCollision const & other) = default;
    ~BallLimitCollision() = default;

    void doCollision() const override;

private:
    std::shared_ptr<gm::Ball> m_ball;
    std::shared_ptr<gm::Platform> m_paddle;
    gm::Player& m_player;
    gm::CollisionSide m_side;
};

}// namespace gm

#endif
