#include "../includes/ballBrickCollision.hpp"
#include "../includes/collisionsManager.hpp"

gm::BallBrickCollision::BallBrickCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::ConstObject> brick ,gm::CollisionSide side)
: m_ball(ball)
, m_brick(brick)
, m_side(side)
{}

gm::Score gm::BallBrickCollision::doCollision() const
{
    sf::Vector2f direction = m_ball->getDirection();

    if(m_side == gm::CollisionSide::noCollisions){
        return gm::Score::noScore;
    }

    gm::ballCollisinCases[m_side](direction);
    m_ball->setDirection(direction);
    m_brick->subLife();

    if(m_brick->isKill()){
        return m_brick->killScore();
    }else{
        return gm::Score::noScore;
    }
}