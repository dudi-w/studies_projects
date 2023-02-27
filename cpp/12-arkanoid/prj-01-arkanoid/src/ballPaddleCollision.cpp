#include "../includes/ballPaddleCollision.hpp"
#include <iostream>

gm::BallPaddleCollision::BallPaddleCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::Platform> brick ,gm::CollisionSide side)
: m_ball(ball)
, m_paddle(brick)
, m_side(side)
{}

gm::Score gm::BallPaddleCollision::doCollision() const
{
    sf::Vector2f direction = m_ball->getDirection();

    switch(m_side)
    {
    case gm::CollisionSide::noCollisions:
        return gm::Score::noScore;;

    case gm::CollisionSide::Bottom:
        direction.y = -std::abs(direction.y);
        break;
    
    case gm::CollisionSide::Up:
        direction.y = std::abs(direction.y);
        break;

    case gm::CollisionSide::Right:
        direction.x = -std::abs(direction.x);
        break;

    case gm::CollisionSide::Left:
        direction.x = std::abs(direction.x);
        break;
    }

    m_ball->setDirection(direction);
    return gm::Score::noScore;
}