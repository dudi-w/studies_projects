#include "../includes/ballLimitCollision.hpp"
#include "../includes/collisionsManager.hpp"

gm::BallLimitCollision::BallLimitCollision(std::shared_ptr<gm::Ball> ball, std::shared_ptr<gm::Platform> paddle ,gm::Player& player, gm::CollisionSide side)
: m_ball(ball)
, m_paddle(paddle)
, m_player(player)
, m_side(side)
{}

void gm::BallLimitCollision::doCollision() const
{
    sf::Vector2f direction = m_ball->getDirection();

    if(m_side == gm::CollisionSide::noCollisions){
        return;
    }

    if(m_side == gm::CollisionSide::Bottom){
        m_player.subLife();
        m_ball->reset();
        m_paddle->reset();
        return;
    }

    gm::ballCollisinCases[m_side](direction);
    m_ball->setDirection(direction);
    return;
}