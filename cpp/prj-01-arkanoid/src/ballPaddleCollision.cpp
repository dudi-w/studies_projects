#include "../includes/collisionsManager.hpp"
#include "../includes/ballPaddleCollision.hpp"

gm::BallPaddleCollision::BallPaddleCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::Platform> brick ,gm::CollisionSide side)
: m_ball(ball)
, m_paddle(brick)
, m_side(side)
{}

void gm::BallPaddleCollision::doCollision() const
{
    if(m_side == gm::CollisionSide::noCollisions){
        return;
    }

    sf::Vector2f direction = m_ball->getDirection();
    gm::ballCollisinCases[m_side](direction);
    m_ball->setDirection(direction);
    return;
}