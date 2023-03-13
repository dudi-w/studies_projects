#include "../includes/ballBrickCollision.hpp"
#include "../includes/collisionsManager.hpp"
#include <iostream>

gm::BallBrickCollision::BallBrickCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::ConstObject> brick ,gm::CollisionSide side)
: m_ball(ball)
, m_brick(brick)
, m_side(side)
{}

uint16_t gm::BallBrickCollision::doCollision() const
{
    sf::Vector2f direction = m_ball->getDirection();

    if(m_side == gm::CollisionSide::noCollisions){
        return 0;
    }

    gm::ballCollisinCases[m_side](direction);
    m_ball->setDirection(direction);
    m_brick->subLife();

    if(m_brick->isKill()){
        return m_brick->killScore();
    }
    return 0;
}